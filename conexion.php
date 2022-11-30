<?php
$hostname = "localhost";
$database = "s_humedad";
$username"root";
$password ="";

$conexion= new mysqli ($host,$user,$password,$database);
if($conexion->connect_errno){
	echo " no hay conexion";
}

?>