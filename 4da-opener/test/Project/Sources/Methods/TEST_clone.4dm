//%attributes = {}
$source:=Folder:C1567(fk resources folder:K87:11).folder("v2004").file("test.4DA")
$target:=Folder:C1567(fk resources folder:K87:11).folder("v13").file("test.4DB")

$clone:=Folder:C1567(fk desktop folder:K87:19).file("clone.4DB")

If (Not:C34($clone.exists))
	$clone:=$target.copyTo($clone.parent; $clone.fullName)
	$status:=Clone structure file($source.platformPath; $clone.platformPath)
End if 