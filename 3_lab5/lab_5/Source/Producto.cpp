#include "../Header/Producto.h"

Producto::Producto(string codigo, string descripcion, int precio) :Comida(codigo, descripcion) {

}
void Producto::asociarAMenu(Menu *m, int cantidad) {
	MenuProducto *mp = new MenuProducto(m, cantidad,this);
	esContenidoEn.insert(mp);

}
void Producto::darDeBajaComida() {
	set<MenuProducto*>::iterator iter;
	for (iter = this->esContenidoEn.begin(); iter != this->esContenidoEn.begin(); iter++) {
		(*iter)->desvincularProductoDeMenu();
	}
}

