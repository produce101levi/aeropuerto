#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


class Usuario{
    
private:
    int edad;
    string nombre;
    string localizacion;
    int counter;
public:
    Usuario(int, string, string); //Constructor
    Usuario();
    void ingresar();
    void registrarUsuario();
    void contarKmUsuario();
    void menu();
    void inicioMenu();
    void resCanVuelo();
};

class Vuelo{

    
private:
    int numVuelo;
    string nombreVuelo;
    string lugar;
    float precio;
    string fecha;
    string clase;
    int duracion;
    float kilometraje;
    string detallesPasajeros;
    string detallesAvion;
    
public:
    Vuelo(int, string, string, float, string, string, int, float, string, string);
    Vuelo();
    int getNumVuelo();
    int setNumVuelo();
    string getNombreVuelo();
    string setNombreVuelo();
    string setLugar();
    string getLugar();
    float setPrecio();
    float getPrecio();
    string setFecha();
    string getFecha();
    string setClase();
    string getClase();
    int setDuracion();
    int getDuracion();
    float getKilometraje();
    float setKilometraje();
    string setDetallesPasajeros();
    string getDetallesPasajeros();
    string setDetallesAvion();
    string getDetallesAvion();
    void buscarVuelo();
    void descuento();
    
    
};

float precioAlemania = 120000.00;
float precioBrasil = 20000.00;
float precioCatar = 30000.00;
float precioCanada = 100000.00;
float precioChile = 50000.00;



Vuelo::Vuelo(int _numVuelo, string _nombreVuelo, string _lugar, float _precio, string _fecha, string _clase, int _duracion, float _kilometraje, string _detallesPasajeros, string _detallesAvion){
    numVuelo = _numVuelo;
    nombreVuelo = _nombreVuelo;
    lugar = _lugar;
    precio = _precio;
    fecha = _fecha;
    clase = _clase;
    duracion = _duracion;
    kilometraje = _kilometraje;
    detallesPasajeros = _detallesPasajeros;
    detallesAvion = _detallesAvion;
}

Vuelo::Vuelo(){
    
}



void Usuario::menu(){
    int val;
    cout<<"----------------------------------------"<<endl;
    cout<<"Selecciona 1 para buscar un vuelo"<<endl;
    cout<<"Selecciona 2 para registrar tus kilómetros"<<endl;
    cout<<"Selecciona 3 para reservar o cancelar un vuelo"<<endl;
    cout<<"Selecciona 4 para salir"<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>val;
    if (val == 1){
        Vuelo bsq = Vuelo();
        
        bsq.buscarVuelo();
        
    }
    if (val == 2){
        Usuario ct = Usuario();
        ct.contarKmUsuario();
        
    }
    if (val == 3){
        Usuario ct = Usuario();
        ct.resCanVuelo();
        
    }
    if (val == 4){
        cout<<"----------------------------------------"<<endl;
        cout<<"Gracias por usar este servicio."<<endl;
        cout<<"----------------------------------------"<<endl;
        
    }
}

int tf=0;

void Usuario::resCanVuelo(){
    string da;
    int val;
    
    
    cout<<"----------------------------------------"<<endl;
    cout<<"Bienvenido. Selecciona 1 para reservar un vuelo y 2 para cancelar un vuelo. Selecciona 3 para regresar al menú."<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>val;
    if(val==1){
        cout<<"Inserta el país cuyo vuelo quieres reservar."<<endl;
        cin>>da;
        
        if(da == "Alemania"){
            cout<<"Has reservado tu vuelo a Frankfurt, Alemania, con éxito. Costará $"<<precioAlemania<<"y saldrá el 5 de marzo del 2023."<<endl;
            tf = 1;
        }
        if(da == "Brasil"){
            cout<<"Has reservado tu vuelo a Brasilia, Brasil, con éxito. Costará $"<<precioBrasil<<" y saldrá el 7 de junio de 2023."<<endl;
            tf = 2;
        }
        if(da == "Canadá"){
            cout<<"Has reservado tu vuelo a Quebec, Canadá, con éxito. Costará $"<<precioCanada<<" y saldrá el 3 de abril de 2023."<<endl;
            tf = 3;
        }
        if(da == "Catar"){
            cout<<"Has reservado tu vuelo a Doha, Catar, con éxito. Costará"<<precioBrasil<<" y saldrá el 28 de febrero de 2023."<<endl;
            tf = 4;
        }
        if(da == "Chile"){
            cout<<"Has reservado tu vuelo a Santiago, Chile, con éxito. Costará $"<<precioChile<<" y saldrá el 1 de enero de 2023."<<endl;
            tf = 5;
        }
        Usuario ct = Usuario();
        ct.resCanVuelo();
        
    }
    if(val==2){
        cout<<"Inserta el país cuyo vuelo quieres cancelar."<<endl;
        cin>>da;
        if(tf == 1){
            if(da == "Alemania"){
                cout<<"Has cancelado tu vuelo a Frankfurt, Alemania."<<endl;
            }
        }
        if(tf == 2){
            if(da == "Brasil"){
                cout<<"Has cancelado tu vuelo a Brasilia, Brasil."<<endl;
            }
        }
        if(tf == 3){
            if(da == "Canadá"){
                cout<<"Has cancelado tu vuelo a Quebec, Canadá."<<endl;
            }
        }
        if(tf == 4){
            if(da == "Catar"){
                cout<<"Has cancelado tu vuelo a Doha, Catar."<<endl;
            }
        }
        if(tf == 5){
            if(da == "Chile"){
                cout<<"Has cancelado tu vuelo a Santiago, Chile."<<endl;
            }
        }
        else{
            cout<<"No tienes vuelos a cancelar."<<endl;
        }

        Usuario ct = Usuario();
        ct.resCanVuelo();
        
    }
    if (val==3){
        Usuario u = Usuario();
        u.menu();
    }

    
                

}
void Vuelo::buscarVuelo(){
    
    ifstream archivoNumVuelo;
    ifstream archivoNombreVuelo;
    ifstream archivoPaises;
    ifstream archivoCostos;
    ifstream archivoFechas;
    ifstream archivoDuracion;
    ifstream archivoKilometraje;
    ifstream archivoDetalles;
    
    
    string busq;
    int val1 = 0;
    cout<<"----------------------------------------"<<endl;
    cout<<"Selecciona la opción 1 si quieres abrir el menú, selecciona la opción 2 si quieres ver los detalles de todos los vuelos."<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>val1;
    if (val1==1){
        int val2;
        cout<<"----------------------------------------"<<endl;
        cout<<"Selecciona 1 para buscar vuelo por número de vuelo"<<endl;
        cout<<"Selecciona 2 para buscar vuelo por nombre de vuelo"<<endl;
        cout<<"Selecciona 3 para buscar vuelo por destino"<<endl;
        cout<<"Selecciona 4 para buscar vuelo por precio"<<endl;
        cout<<"Selecciona 5 para buscar vuelo por fecha"<<endl;
        cout<<"Selecciona 6 para buscar vuelo por duración"<<endl;
        cout<<"Selecciona 7 para buscar vuelo por kilometraje"<<endl;
        cout<<"----------------------------------------"<<endl;
        cin>>val2;
        if (val2 == 1){
            string da;
            string ps;
            archivoNumVuelo.open("NumVuelo.txt");
            cout<<"Inserta el número de vuelo que quieres buscar: ";
            cin>>busq;
            if (archivoNumVuelo.is_open()){
                while(getline(archivoNumVuelo, da)){
                    if (busq == da){
                        if(da == "1003"){
                            ps = "Alemania";
                        }
                        if(da == "403"){
                            ps = "Brasil";
                        }
                        if(da == "23"){
                            ps = "Canadá";
                        }
                        if(da == "100"){
                            ps = "Catar";
                        }
                        if(da == "45"){
                            ps = "Chile";
                        }
                        cout<<"Resultado: "<<da<<", vuelo a: "<<ps<<endl;
                    }
                }
                
            }
        }
        if (val2 == 2){
            string da;
            string ps;
            archivoNombreVuelo.open("NombreVuelo.txt");
            cout<<"Inserta el nombre de vuelo que quieres buscar: ";
            cin>>busq;
            if (archivoNombreVuelo.is_open()){
                while(getline(archivoNombreVuelo, da)){
                    if (busq == da){
                        if(da == "Vuelo a Frankfurt, Alemania"){
                            ps = "Alemania";
                        }
                        if(da == "Vuelo a Brasilia, Brasil"){
                            ps = "Brasil";
                        }
                        if(da == "Vuelo a Quebec, Canadá"){
                            ps = "Canadá";
                        }
                        if(da == "Vuelo a Doha, Catar"){
                            ps = "Catar";
                        }
                        if(da == "Vuelo a Santiago, Chile"){
                            ps = "Chile";
                        }
                        cout<<"Resultado: "<<da<<", vuelo a: "<<ps<<endl;
                    }
                }
                
            }
        }
        if (val2 == 3){
            string da;
            string ps;
            archivoPaises.open("Países.txt");
            cout<<"Inserta el país que quieres buscar: ";
            cin>>busq;
            if (archivoPaises.is_open()){
                while(getline(archivoPaises, da)){
                    if (busq == da){
                        if(da == "Alemania"){
                            ps = "Frankfurt, Alemania";
                        }
                        if(da == "Brasil"){
                            ps = "Brasilia, Brasil";
                        }
                        if(da == "Canadá"){
                            ps = "Quebec, Canadá";
                        }
                        if(da == "Catar"){
                            ps = "Doha, Catar";
                        }
                        if(da == "Chile"){
                            ps = "Santiago, Chile";
                        }
                        cout<<"Resultado: "<<da<<", vuelo a: "<<ps<<endl;
                    }
                }
                
            }
        }
        if (val2 == 4){
            string da;
            string ps;
            archivoCostos.open("Costos.txt");
            cout<<"Inserta el costo del vuelo que quieres buscar: ";
            cin>>busq;
            if (archivoCostos.is_open()){
                while(getline(archivoCostos, da)){
                    if (busq == da){
                        if(da == "120,000.00"){
                            ps = "Alemania";
                        }
                        if(da == "20,000.00"){
                            ps = "Brasil";
                        }
                        if(da == "30,000.00"){
                            ps = "Canadá";
                        }
                        if(da == "100,000.00"){
                            ps = "Catar";
                        }
                        if(da == "50,000.00"){
                            ps = "Chile";
                        }
                        cout<<"Resultado: $"<<da<<", vuelo a: "<<ps<<endl;
                    }
                }
                
            }
        }
        if (val2 == 5){
            string da;
            string ps;
            archivoFechas.open("Fechas.txt");
            cout<<"Inserta la fecha del vuelo que quieres buscar (en formato dd/mes): ";
            cin>>busq;
            if (archivoFechas.is_open()){
                while(getline(archivoFechas, da)){
                    if (busq == da){
                        if(da == "05/marzo"){
                            ps = "Frankfurt, Alemania";
                        }
                        if(da == "07/junio"){
                            ps = "Brasilia, Brasil";
                        }
                        if(da == "03/abril"){
                            ps = "Quebec, Canadá";
                        }
                        if(da == "28/febrero"){
                            ps = "Doha, Catar";
                        }
                        if(da == "1/enero"){
                            ps = "Santiago, Chile";
                        }
                        cout<<"Resultado: "<<da<<", vuelo a: "<<ps<<endl;
                    }
                }
                
            }
        }
        if (val2 == 6){
            string da;
            string ps;
            archivoDuracion.open("Horas.txt");
            cout<<"Inserta la duración del vuelo que quieres buscar (en horas): ";
            cin>>busq;
            if (archivoDuracion.is_open()){
                while(getline(archivoDuracion, da)){
                    if (busq == da){
                        if(da == "10"){
                            ps = "Frankfurt, Alemania";
                        }
                        if(da == "7"){
                            ps = "Brasilia, Brasil";
                        }
                        if(da == "6"){
                            ps = "Quebec, Canadá";
                        }
                        if(da == "13"){
                            ps = "Doha, Catar";
                        }
                        if(da == "10"){
                            ps = "Santiago, Chile";
                        }
                        cout<<"Resultado: "<<da<<" horas, vuelo a: "<<ps<<endl;
                    }
                }
                
            }
        }
        if (val2 == 7){
            string da;
            string ps;
            archivoKilometraje.open("Kilometraje.txt");
            cout<<"Inserta la distancia en km del vuelo que quieres buscar: ";
            cin>>busq;
            if (archivoKilometraje.is_open()){
                while(getline(archivoKilometraje, da)){
                    if (busq == da){
                        if(da == "9442"){
                            ps = "Frankfurt, Alemania";
                        }
                        if(da == "6924"){
                            ps = "Brasilia, Brasil";
                        }
                        if(da == "3624"){
                            ps = "Quebec, Canadá";
                        }
                        if(da == "13869"){
                            ps = "Doha, Catar";
                        }
                        if(da == "7353"){
                            ps = "Santiago, Chile";
                        }
                        cout<<"Resultado: "<<da<<"km, vuelo a: "<<ps<<endl;
                    }
                }
                
            }
        }
        
        if (val2 > 8){
            cout<<"Error. No insertaste un valor válido."<<endl;
        }
    }
    if (val1 == 2){
        string detalles;
        archivoDetalles.open("VueloDetalles.txt");
        if (archivoDetalles.is_open()){
            while (getline(archivoDetalles, detalles)){
                cout<<detalles<<endl;
            }
        }
        
    }
    Usuario mn = Usuario();
    mn.menu();
    
}

void Usuario::ingresar(){
    
    int val = 0;
    cout<<"----------------------------------------"<<endl;
    cout<<"Selecciona 1 si es tu primera vez ingresando con nosotros."<<endl;
    cout<<"Selecciona 2 si ya tienes una cuenta con nosotros."<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>val;
    if (val == 1){
        ofstream archivoUsuario;
        archivoUsuario.open("Usuarios.txt");
        string username;
        cout<<"----------------------------------------"<<endl;
        cout<<"Inserta el nombre de usuario que quieres tener."<<endl;
        cout<<"----------------------------------------"<<endl;
        cin>>username;
        archivoUsuario << username;
        cout<<"----------------------------------------"<<endl;
        cout<<"Has accedido con éxito a tu cuenta."<<endl;
        cout<<"----------------------------------------"<<endl;
        Usuario mn = Usuario();
        mn.menu();
        
        archivoUsuario.close();
        
    }
    if (val == 2){
        ifstream archivoUsuario;
        string username;
        string usercor;
        archivoUsuario.open("Usuarios.txt");
        
        cout<<"Inserta tu usuario:"<<endl;
        cin>>username;
        if (archivoUsuario.is_open()){
            while (getline(archivoUsuario,usercor)){
                if (usercor == username){
                    cout<<"----------------------------------------"<<endl;
                    cout<<"Has accedido con éxito a tu cuenta."<<endl;
                    cout<<"----------------------------------------"<<endl;
                    Usuario mn = Usuario();
                    mn.menu();
                }
                else{
                    cout<<"----------------------------------------"<<endl;
                    cout<<"No has accedido con una cuenta válida. Adiós."<<endl;
                    cout<<"----------------------------------------"<<endl;
                    Usuario u = Usuario();
                    u.inicioMenu();
                }
            }
        }
    

    }
}

//Constructor, para inicializar los atributos
Usuario::Usuario(int _edad,string _nombre, string _localizacion){
    edad = _edad;
    nombre = _nombre;
    localizacion = _localizacion;
}
Usuario::Usuario(){
    
}





int val = 0;
int kmUsuario = 0;

void Usuario::contarKmUsuario(){
    int countKm;
    int yn;
    cout<<"¿Cuántos Km has viajado?: "<<endl;
    cin>>countKm;
    kmUsuario = kmUsuario + countKm;
    cout<<"En total has viajado "<<kmUsuario<<"km"<<endl;
    if (kmUsuario>=50000){
        cout<<"----------------------------------------"<<endl;
        cout<<"Por viajar con nosotros, se te aplica un descuento del 40% en todos tus vuelos!"<<endl;
        
        cout<<"----------------------------------------"<<endl;
        cout<<"Selecciona 1 para mostrar tus nuevos precios, selecciona 2 para regresar: "<<endl;
        cin>>yn;
        precioAlemania = precioAlemania * 0.6;
        precioBrasil = precioBrasil * 0.6;
        precioCatar = precioCatar * 0.6;
        precioCanada = precioCanada * 0.6;
        precioChile = precioChile *0.6;
        if (yn == 1){
            
            cout<<"Precio para Alemania ahora: "<<precioAlemania<<endl;
            cout<<"Precio para Brasil ahora: "<<precioBrasil<<endl;
            cout<<"Precio para Catar ahora: "<<precioCatar<<endl;
            cout<<"Precio para Canadá ahora: "<<precioCanada<<endl;
            cout<<"Precio para Chile ahorta: "<<precioChile<<endl;
        }
        if (yn == 2){
            Usuario u = Usuario();
            u.contarKmUsuario();
        }
        
    }
    cout<<"----------------------------------------"<<endl;
    cout<<"Selecciona 1 para continuar agregando km."<<endl;
    cout<<"Selecciona 2 para regresar al menú."<<endl;
    cout<<"Selecciona 3 para salir."<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>val;
    if(val==1){
        Usuario u = Usuario();
        u.contarKmUsuario();
    }
    if(val==2){
        Usuario mn = Usuario();
        mn.menu();
    }
    if(val==3){
        cout<<"Gracias por usar este servicio."<<endl;
    }
}

void Usuario::inicioMenu(){
    int linea;
    cout<<"----------------------------------------"<<endl;
    cout<<"Bienvenid@ al servicio LeviAereolínea."<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"Selecciona 1 para ingresar con tu usuario, selecciona 2 para salir."<<endl;
    cin>>linea;
    if (linea==1){
        Usuario u = Usuario();
        
        u.ingresar();
        
    }
    if (linea==2){
        cout<<"----------------------------------------"<<endl;
        cout<<"Gracias por usar este servicio."<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}



int main() {
    
    Usuario u = Usuario();
    u.inicioMenu();
    
    
 
    return 0;
}

