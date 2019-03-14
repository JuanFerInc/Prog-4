

class DtFecha{
private:
	int d, m, a;
public:
	//Constructores
	DtFecha(int,int,int);

	//getters
	int getDia();
	int getMes();
	int getAnio();

	//setters
	void setDia(int);
	void setMes(int);
	void setAnio(int);	
	void setDtFecha(int, int, int);


	//Destructor
 	~DtFecha();

 	//Otras

 	DtFecha operator=(DtFecha);

}