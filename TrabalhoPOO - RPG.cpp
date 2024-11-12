#include <iostream>
#include <vector>

using namespace std;

class Personagem{
protected:
    string nome;
    string tipoClasse;
    int ptsVidaBase;
    int danoBase;
    int agilidade; // Adicionar valores de agilidade (Talvez?)
    
public:
    void setNome(string nome){
        this->nome=nome;
    }

    void setClasse(string tipoClasse){
        this->tipoClasse=tipoClasse;
    }

    string getNome(){
        return this->nome;
    }

    string getClasse(){
        return this->tipoClasse;
    }
    
    int getDano(){
        return this->danoBase;
    }
    
    int getPtsVida(){
        return this->ptsVidaBase;
    }
    
    int PtsVidaIn(){
        return this->ptsVidaBase=100;
    }
    
    int DanoIn(){
        return this->danoBase=20;
    }

};

class Humano: public Personagem{
public:
    Humano(){
        cout << "Seu personagem eh um humano" << endl;
    }

    void CalcDano(int danoBase){
        this->danoBase = danoBase;
    }

    void CalcPtsVida(int ptsVidaBase){
        this->ptsVidaBase=ptsVidaBase;
    }
};

class Anao: public Personagem{
public:
    Anao(){
        cout << "Seu personagem eh um anao" << endl;
    }

    void CalcDano(int danoBase){
        this->danoBase = danoBase - 5;
    }

    void CalcPtsVida(int ptsVidaBase){
        this->ptsVidaBase=ptsVidaBase + 20;
    }
};

class Elfo: public Personagem{
public:
    Elfo(){
    cout << "Seu personagem eh um elfo" << endl;
    }

    void CalcDano(int danoBase){
        this->danoBase = danoBase - 10;
    }

    void CalcPtsVida(int ptsVidaBase){
        this->ptsVidaBase=ptsVidaBase - 10;
    }

};

class Armas{
protected:
    string orientacaoMao;
    int modDano;
};

class Espada: public Armas{
    Espada(){
        cout << "Seu personagem empunha uma espada" << endl;
    }

    void setOrientMao(string orientacaoMao){
        this->orientacaoMao = orientacaoMao;
    }

    void setModDano(int modDano){
        this->modDano;
    }
};

class Arco: public Armas{
    Arco(){
        cout << "Seu personagem empunha um arco" << endl;
    }
};

class Machado: public Armas{
    Machado(){
        cout << "Seu personagem empunha um machado" << endl;
    }
};

class Cajado: public Armas{
    Cajado(){
        cout << "Seu personagem empunha um cajado ou cetro" << endl;
    }
};

int main(){

    int quantidade, raca;
    string nomeP;
	
    cout <<"----------------------------------"<< endl;
    cout <<"=|CRIACAO DE PERSONAGEM PARA RPG|="<< endl;
    cout <<"----------------------------------"<< endl;
	
    cout << "Quantos personagens serao criados? " << endl;
	cin >> quantidade;

    vector<Personagem> criacao;

    for (int i=0; i < quantidade; i++)
	{
		cout << "Nome do personagem: " << i+1 << endl;
		cin >> nomeP;
		
        cout << "Escolha uma raca:  " << endl;
        cout << "1- Humano.  " << endl;
        cout << "2- Anao.  "   << endl;
        cout << "3- Elfo.  "   << endl;
		cin >> raca;
		
		cout << endl;
		
        if(raca == 1)
		{
            Humano personagem;
            personagem.setNome(nomeP);
            personagem.setClasse("Humano");
            criacao.push_back(personagem);
        }
		else if(raca == 2)	
		{
			Anao personagem;
            personagem.setNome(nomeP);
            personagem.setClasse("Anao");
            criacao.push_back(personagem);
		}
		else if(raca == 3)	
		{
			Elfo personagem;
            personagem.setNome(nomeP);
            personagem.setClasse("Elfo");
            criacao.push_back(personagem);
		}
	}
	
	for (int i = 0; i < criacao.size(); i++)
	{
		cout << "Nome: " << criacao[i].getNome() << endl;
		cout << "Classe: "  << criacao[i].getClasse()  << endl;
		cout << "Dano Total: " << criacao[i].getDano() << endl;
		cout << "Vida Total: " << criacao[i].getPtsVida() << endl;		
	}
}
