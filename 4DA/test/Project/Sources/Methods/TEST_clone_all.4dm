//%attributes = {}
$clone:=Folder:C1567(fk desktop folder:K87:19).file("clone-all.4DB")

If (Not:C34($clone.exists))
	
	$path:=$clone.platformPath
	
	Begin SQL
		CREATE DATABASE IF NOT EXISTS DATAFILE :$path;
		USE DATABASE DATAFILE :$path AUTO_CLOSE;--set PR4D
		USE DATABASE SQL_INTERNAL;
	End SQL
	
	$source:=Folder:C1567(fk resources folder:K87:11).folder("v2004").file("test.4DA")
	$status:=Clone structure file($source.platformPath; $clone.platformPath)
	
	//PR4D damage!
	
End if 