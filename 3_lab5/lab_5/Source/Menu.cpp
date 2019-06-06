#include "../Header/Menu.h"

void Menu::darDeBajaComida() {

}

void Menu::asociarmeAMenuProducto(MenuProducto *mp) {
	productosContenidos.insert(mp);
}

bool Menu::desvincularM() {
	set<MenuProducto*>::iterator iter;
	for (iter = this->productosContenidos.begin(); iter != this->productosContenidos.end(); iter++) {}
}