 
#ifndef DTVEHICULO_H
#define DTVEHICULO_H

class DtVehiculo {
    private:
        int nroSerie;
        float porcentaje;
        float precioBase;
    public:
        //Constructor
        DtVehiculo(int nroSerie,float porcentaje,float precioBase);
        //Getters
        int get_nroSerie();
        float get_porcentaje();
        float get_precioBase();
        //Destructor
        ~DtVehiculo();
}

#endif
