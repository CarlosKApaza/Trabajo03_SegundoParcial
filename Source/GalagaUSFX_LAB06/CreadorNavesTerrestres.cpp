// Fill out your copyright notice in the Description page of Project Settings.


#include "CreadorNavesTerrestres.h"

#include "NaveTerrestre_Transporte.h"
#include "NaveTerrestre_Artilleria.h"

ANaveEnemiga* ACreadorNavesTerrestres::CrearNaveEnemiga(FString NombreNaveSKU, FVector PosicionNave, FRotator Rotacion)
{
	// Selecciona que nave crear dependiendo de la cadena pasada
	if (NombreNaveSKU.Equals("NaveTerrestre_Transporte")) {
		return GetWorld()->SpawnActor<ANaveTerrestre_Transporte>(ANaveTerrestre_Transporte::StaticClass(),
			PosicionNave, Rotacion);
	}
	else if (NombreNaveSKU.Equals("NaveTerrestre_Artilleria")) {
		return GetWorld()->SpawnActor<ANaveTerrestre_Artilleria>(ANaveTerrestre_Artilleria::StaticClass(),
			PosicionNave, Rotacion);
	}
	else return nullptr; //Si la cadena es nula o no coincide con ninguna nave, devuelve nullptr
}

