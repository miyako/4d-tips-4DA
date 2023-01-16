/* --------------------------------------------------------------------------------
 #
 #  4DPlugin-4DA.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : 4DA Opener
 #	author : miyako
 #	2023/01/13
 #  
 # --------------------------------------------------------------------------------*/

#include "4DPlugin-4DA.h"

#pragma mark -

void PluginMain(PA_long32 selector, PA_PluginParameters params) {
    
	try
	{
        switch(selector)
        {
			// --- 4DA
            
			case 1 :
                Clone_structure_file(params);
                break;

        }

	}
	catch(...)
	{

	}
}

#pragma mark -

static void Clone_structure_file(PA_PluginParameters params) {

    PA_ObjectRef status = PA_CreateObject();
    PA_CollectionRef resources = PA_CreateCollection();
    
    ob_set_b(status, L"success", false);
    
    PA_Unistring *src = PA_GetStringParameter(params, 1);//.4DA
    PA_Unistring *dst = PA_GetStringParameter(params, 2);//.4DB
    
    PA_ErrorCode errorcode = eER_NoErr;
    
    if(src) {
        short srcRes = PA_OpenResFile(src);
        errorcode = PA_GetLastError();
        
        if((errorcode == eER_NoErr) && (srcRes != -1)) {
            
                short dstRes = PA_OpenResFile(dst);
                errorcode = PA_GetLastError();
            
            if((errorcode == eER_NoErr) && (dstRes != -1)) {
                
                PA_long32 countKinds = PA_GetResourceKindList(srcRes, 0L);
                if(countKinds != 0)
                {
                    std::vector<PA_ulong32>bufk(countKinds);
                    PA_GetResourceKindList(srcRes, &bufk[0]);
                    for(PA_ulong32 i = 0; i < countKinds; ++i)
                    {
                        PA_ulong32 kind = bufk[i];
                        
                        PA_long32 countResources = PA_GetResourceIDList(srcRes, kind, 0L);
                        
                        std::vector<PA_long32>bufr(countResources);
                        PA_GetResourceIDList(srcRes, kind, (PA_long32 *)&bufr[0]);
                                                
                        for(PA_ulong32 j = 0; j < countResources; ++j)
                        {
                            PA_long32 resourceID = bufr[j];
                            
                            PA_long32 resourceSize = PA_GetResource(srcRes, kind, resourceID, 0L);
                            //PA_GetResourceSize is buggy!
                            
                            PA_ObjectRef resource = PA_CreateObject();
                            ob_set_n(resource, L"size", resourceSize);
                            ob_set_n(resource, L"ID", resourceID);
                            
                            std::vector<PA_Unichar>name(33);
                            PA_GetResourceName(srcRes, kind, resourceID, &name[0]);
                            errorcode = PA_GetLastError();
                            if(errorcode == eER_NoErr) {
                                CUTF16String t(&name[0]);
                                ob_set_a(resource, L"name", &t);
                            }

                            char asciiResourceID[5];
                            asciiResourceID[3] = (kind & 0x000000FF)      ;
                            asciiResourceID[2] = (kind & 0x0000FF00) >> 8 ;
                            asciiResourceID[1] = (kind & 0x00FF0000) >> 16;
                            asciiResourceID[0] = (kind & 0xFF000000) >> 24;
                            asciiResourceID[4] = 0;
                            ob_set_s(resource, L"type", asciiResourceID);
                            
                            if(resourceSize != 0) {
                                
                                std::vector<unsigned short>bufd(resourceSize);
                                PA_long32 receivedResourceSize = PA_GetResource(srcRes, kind, resourceID, (char *)&bufd[0]);
                                errorcode = PA_GetLastError();
                                
                                PA_long32 newID = PA_CreateResource(dstRes, kind, -1, &name[0], (char *)&bufd[0], resourceSize);
                                errorcode = PA_GetLastError();
                                if(errorcode == eER_NoErr){
                                    PA_UpdateResFile(dstRes);
                                    ob_set_n(resource, L"newID", newID);
                                }else{
                                    ob_set_n(resource, L"error", errorcode);
                                }
                            }

                            PA_Variable v = PA_CreateVariable(eVK_Object);
                            PA_SetObjectVariable(&v, resource);
                            PA_SetCollectionElement(resources, PA_GetCollectionLength(resources), v);
                            PA_ClearVariable(&v);
                        }
                        
                    }
                }

                ob_set_b(status, L"success", true);
                PA_CloseResFile(dstRes);
                
            }else{
                ob_set_n(status, L"error", errorcode);
                ob_set_s(status, L"errorMessage", "failed to open .4DB file");
            }
            PA_CloseResFile(srcRes);
        }else{
            ob_set_n(status, L"error", errorcode);
            ob_set_s(status, L"errorMessage", "failed to open .4DA file");
        }
    }
    
    ob_set_c(status, L"resources", resources);
    
    PA_ReturnObject(params, status);
}
