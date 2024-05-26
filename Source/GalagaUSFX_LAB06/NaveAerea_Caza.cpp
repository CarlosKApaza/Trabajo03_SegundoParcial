// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAerea_Caza.h"

void ANaveAerea_Caza::BeginPlay()
{
	Super::BeginPlay();
}

ANaveAerea_Caza::ANaveAerea_Caza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_Aerea_Caza.TwinStickUFO_Aerea_Caza'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	
	// Definimos la velocidad en la que se movera la nave en el eje X porque esta creada de forma vertical
	VelocidadYCaza = -250.0f;

    // Vida de la Nave
    energia = 10; // Inicializar la energia que tendra la nave
	resistencia = 30; // Inicializar la resistencia que tendra la nave

    // Recompensa de la nave cuando se destruya
	recompensaNave = 10;  // la nave otorga 10 puntos al ser destruida
        
}

void ANaveAerea_Caza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Mover(DeltaTime);
}

void ANaveAerea_Caza::Mover(float DeltaTime)
{
    //Obtenemos la posici�n actual del actor
    FVector PosicionActual = GetActorLocation();

    // Generamos nuevas coordenadas X e Y aleatorias
    float NuevaX = 0.0f; // No se mueve en el eje X

    // Calculamos la nueva posici�n en el eje Y
    float NuevaPosicionY = PosicionActual.Y + (VelocidadYCaza * DeltaTime);

    // Verificamos si la nave ha alcanzado el l�mite superior o inferior
    if (NuevaPosicionY <= -1000.0f || NuevaPosicionY >= 1000.0f )
    {
        // Cambiamos la direcci�n multiplicando por -1
        VelocidadYCaza *= -1.0f;
    }
    // Establecemos la nueva posici�n del actor
    SetActorLocation(FVector(PosicionActual.X + NuevaX, NuevaPosicionY, PosicionActual.Z));
}

int32 ANaveAerea_Caza::RecibirDanio(float dano)
{
    // Restamos la energia de la nave
    energia -= dano;

    // Verificamos si la nave ha sido destruida
    if (energia <= 0)
    {
        // Destruimos la nave
        Destroy();
		return recompensaNave; // si la nave ha sido destruida, retornamos la recompensa
    }
	return 0; // si la nave no ha sido destruida, retornamos 0
}


//void ANaveEnemigaCaza::RecibirDanio(float Cantidad)
//{
//	resistencia -= Cantidad;
//
//	if (resistencia <= 0)
//	{
//
//		energia -= Cantidad;    // Reducir la energ�a seg�n la cantidad de da�o recibido
//	}
//	if (energia <= 0)        // Verificar si la energ�a llega a cero o menos
//	{
//		Destroy();       // La nave ha sido destruida
//	}
//}