#ifndef VEHICULO.H
#define VEHICULO.H

class Vehiculo{
    private:
        int nroSerie;
        float porcentajeBateria;
        float precioBase;
    public:
        //Cons
        Vehiculo(int nroSerie, float porcentajeBateria, float precioBase);
        //Get
        int getnroSerie();
        float getporcentajeBateria();
        float getprecioBase();
        //Set
        void setnroSerie(int nroserie);
        void setporcentajeBateria(float porcentajeBateria);
        void setprecioBase(float precioBase);
        //Def
        virtual float darPrecioViaje(int duracion, int distancia) = 0;
        
}



#endif
