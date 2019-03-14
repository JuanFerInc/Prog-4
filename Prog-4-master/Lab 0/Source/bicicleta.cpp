#include "../Header/bicicleta.h"

		//Constructor
		Bicicleta(TipoBici tipo, int cantCambios){
            this->tipo = tipo;
            this->cantCambios = cantCambios;
        }

		//Get
		TipoBici getTipo(){
            return this->tipo;
            
        }
		int getcantCambios(){
            return this->cantCambios;
        }

		//Set
		void setTipo(TipoBici tipo){
            this->tipo = tipo;
        }
		void setcantCambios(int cantCambios){
            this->cantCambios = cantCambios;
        }

		//Def
		float darPrecioViaje(int duracion, int distancia){
            float precio;
            precio = preciBase*distancia;
        }
