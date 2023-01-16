//%attributes = {}
$target:=Folder:C1567(fk resources folder:K87:11).folder("v19").file("test.4DB")  //new DB

$clone:=Folder:C1567(fk desktop folder:K87:19).file("clone-v19.4DB")

If (Not:C34($clone.exists))
	$clone:=$target.copyTo($clone.parent; $clone.fullName)
	
	$source:=Folder:C1567(fk resources folder:K87:11).folder("v2004").file("test.4DA")
	$status:=Clone structure file($source.platformPath; $clone.platformPath)
	
	$source:=Folder:C1567(fk resources folder:K87:11).folder("v2004").file("test.4DB")
	$status:=Clone structure file($source.platformPath; $clone.platformPath)
	
End if 