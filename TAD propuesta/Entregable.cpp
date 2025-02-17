/**
    Consideraciones
    El vector consecutivos del CAU solo tiene 3 datos, por lo tanto 3
    posiciones de la 0 a la 2 donde la 0 es el consecutivo de ventas,
    la 1 de servicio tecnico y la 2 de reclamos

 */
/**
    Diseño: Asignar un turno
    Teniendo en cuenta el diseño, al momento de asignar el turno
    se piden 3 valores claves, el primero es el ID unico del usuario,
    el segundo es si tiene o no prioridad al momento de serle
    asignado un turno y por ultimo el tema del cual necesita asesoria.

    Primero se revisa el tema al cual desea hacer cola para poder saber
    el consecutivo; con esto sabemos el indice que necesitamos. Luego
    se revisa si tiene o no prioridad. Se genera en cualquier caso
    una instancia de Persona, con los datos obtenidos como parametros
    y el turno extraido del vector consecutivo; se llena la informacion
    usando los setters. Al momento de fijar el turno a Persona, se edita el vector
    de consecutivos aumentando en 1 el valor correspondiente.
    Al momento de insertar la persona se revisa si tiene prioridad. Usando un
    iterador, si tiene prioridad se establece el iterador al vector.end(), si no
    se establece al vector.begin() Se aplica un vector.insert(iterador,persona).
 */
//Implementación: Asignar un turno

string CAU::asignarTurno(int id, bool prioridad, string tema) {
    int idx = -1;
    vector<int>::iterator it;
    if(tema == "VE"){
        idx = 0;
    }else if(tema == "ST"){
        idx = 1;
    }else(tema == "RE"){
        idx = 2;
    }
    Persona persona;
    persona.fijarId(id);
    persona.fijarPrioridad(prioridad);
    persona.fijarTema(tema);
    persona.fijarTurno(consecutivos[idx]);
    int temp = consecutivos[idx];
    consecutivos[idx] = temp + 1;
    if(persona.obtenerPrioridad()){
        it = colasAtencion.end();   
    }else{
        it = colasAtencion.begin();
    }
    colasAtencion.insert(it,persona);
    return "Insertado"
}
/**

    Diseño: Atender un usuario
    Es importante dentro de la funcion tener 3 varibles enteras temporales
    las cuales almacenan la cantidad de turnos de ese tipo.
    Identificamos cual es la variable mayor y buscamos el proximo
    turno a salir de ese tipo. Buscamos un asesor que pueda atender
    a este caso y le aumentamos el contador de atentidos, posteriormente
    sacamos el turno de la cola.


 */
//
bool CAU::atenderUsuario() {
    vector<Personas>::iterator it = colasAtencion.end();
    int ve = 0,st = 0,re = 0, idx = -1;
    string s;
    bool flag = true;
    int id, turno;
    bool prioridad;
    string tema;
    for(auto p : colasAtencion){
        if(p.obtenerTema() == "VE") ve++;
        if(p.obtenerTema() == "ST") st++;
        if(p.obtenerTema() == "RE") re++;
    }
    if(re == max(ve,max(st,re))) s = "RE";
    if(st == max(ve,max(st,re))) s = "ST";
    if(ve == max(ve,max(st,re))) s = "VE";
    for(int i = colasAtencion.size()-1, ,i>=0; i--){
        if(colasAtencion[i].obtenerTema() == s){
            idx = i;
            break;
        }
        it--;
    }
    for(auto a : asesores){
        if(a.obtenerEstado() == "disponible" && a.obtenerTema() == s){
            a.fijarEstado("ocupado");
            a.agregarAtendido(colasAtencion[idx].obtenerTurno());
            colasAtencion.remove(it);
        }
    }
    return true;

}
/**

    Diseño: Conteo de usuarios atendidos
    Se tiene una variable llamada atentidos empezada en 0. Se itera
    por todo el vector de asesores y en cada uno de ellos se aplica
    el metodo .obtenerAtendidos() hasta conseguir el total

 */


//mplementación: Conteo de usuarios atendidos
int CAU::conteoAtendidos() {
    int aten = 0;
    for(auto a : asesores){
        aten += a.obtenerAtendidos();
    }
    return aten;
}