#include "../Header/monopatin.h"


//Constructor
		Monopatin(bool tieneLuces){
            this->tieneLuces = tieneLuces
        }
		//Get
		bool gettieneLuces(){
            return this->tieneLuces;
        }
		//Set
		void settieneLuces(bool tieneLuces){
            this->tieneLuces = tieneLuces
        }
		//Def
		float darPrecioViaje(int duracion, int distancia){
            float precio;
            if(tieneLuces){
                precio = ((0.5)*duracion) + (distancia*precioBase);
                
            }else{
                precio = distancia*precioBase;
            }
            return precio;
}


