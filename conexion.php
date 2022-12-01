<?php
$hostname = "localhost";
$database = "s_humedad";
$username"root";
$password ="";

$conexion= new mysqli ($hostname,$username,$password,$database);
if($conexion->connect_errno){
	echo " no hay conexion";
}

?>
