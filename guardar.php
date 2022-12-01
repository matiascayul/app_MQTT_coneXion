<?php
include 'conexion.php';
$registro = $_POST['registro'];

$query = "INSERT INTO registrodb ('registro')values ('$registro')";
$resultado =mysqli_query($conexion,$query);

if($resultado){
echo "Guardado";
	
}else{
echo "error al guardar dato";	
	
}

?>
