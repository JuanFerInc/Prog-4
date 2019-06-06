#include "../Header/Menu.h"

void Menu::darDeBajaComida() {

}


bool Menu::desvincularM() {
	set<MenuProducto*>::iterator iter;
	for (iter = this->productosContenidos.begin(); iter != this->productosContenidos.end(); iter++) {}
}