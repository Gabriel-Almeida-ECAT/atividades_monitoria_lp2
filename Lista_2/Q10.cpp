#include <iostream>

using namespace std;

class Node {
    public:
        int data;    // dado armazenado neste nó da lista
        Node *next;  // ponteiro para antecessor da lista
        bool swap;
        bool removed;
        bool n_found;

        Node(){ next = nullptr; swap = false; removed = false; n_found = false; }; // construtor para criar uma lista vazia      
        // insere um objeto na lista, obtendo um novo nó, inserindo n em data e conectando o novo nó ao nodo antecessor. O primeiro nó da lista deve apontar para NULL(fim da lista).
        void insert(int n){
            if(next == nullptr){
                data = n;
                next = new Node();
                return;
            }
            else{
                next->insert(n);
            }
        }  
        
        // Caso exista na lista o inteiro n, remover o nó correspondente a n. Retornar true se removeu. 
        bool remove(int n){
            if(swap){
                data = next->data;
                removed = false;
                next->removed = true;
                swap = false;
                next->swap = true;
                if(n_found){
                    next->n_found = true;
                    n_found = false;
                }
            }
   
            if(data == n && next->next != nullptr){
                if(!n_found && !next->n_found){
                    next->n_found = true;
                    data = next->data;
                    next->swap = true;
                    next->removed = true;
                    next->remove(n);
                }else{
                    next->remove(n);
                }
            }
            else if(data == n && next->next == nullptr){
                this->removeAll();
            }
            else if(data != n && next->next != nullptr){
                next->remove(n);
            }
            else if(next->next == nullptr){
                next->swap = false;
                bool holder = next->removed;
                next->removed = false;
                this->removeAll();
                return holder;
            }
        }
        

        // Retornar true se a lista está vazia
        bool  isEmpty(){
            return (next == nullptr);
        }
        
        // Mostrar todos os elementos da lista
        void  display(){
            if(next->next != nullptr){ 
                printf("%d -> ", data); 
                next->display(); 
            }
            else{
                printf("%d", data); 
                return;
            }
        }
        
        // Remover todos os elementos da lista, devolvendo a memória ao espaço livre. 
        void removeAll(){
            delete next;
            next = nullptr;
        }

        ~Node() {
            this->removeAll();
        }
};


int main(){
    Node N;

    if (N.isEmpty()) cout << "lista vazia" << endl;
    else  cout << "lista não vazia" << endl;  

    N.insert(10);
    N.insert(20);
    N.insert(30);
    N.insert(20);

    N.display();

    if (N.isEmpty()) cout << "\nlista vazia" << endl;
    else  cout << "\nlista nao vazia" << endl;  

    if (N.remove(20)) cout << "\nRemovido" << endl;
    else  cout << "\nNão removido" << endl;  

    N.display();

    N.removeAll();               
    if (N.isEmpty()) cout << "\nlista vazia" << endl;
    else  cout << "\nlista não vazia" << endl;

    N.~Node();

    return 0;
}
