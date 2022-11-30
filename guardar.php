<?php
include 'conexion.php';
$registro = $_POST['registro'];

$query = "INSERT INTO registros ('registro')values ('$registro')";
$resultado =myqli_query($conexion,$query);

if(){
echo "Guardado";
	
}else{
echo "error al guardar dato";	
	
}

?>