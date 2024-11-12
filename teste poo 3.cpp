#include <iostream>
#include <vector>

using namespace std;


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
        this->modDano = modDano;
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

class Personagem{
protected:
    string nome;
    string tipoClasse;
    int ptsVidaBase;
    int danoBase;
    int agilidade; // Adicionar valores de agilidade (Talvez?)
    Armas *item;    
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
    
    virtual int CalcDano(){
		
	}
	
	virtual int CalcPtsVida(){
		
	}

};

class Humano: public Personagem{
public:
    Humano(){
        cout << "Seu personagem e um humano" << endl;
    }

    int CalcDano(int danoBase){
        return this->danoBase=100;
    }

    int CalcPtsVida(int ptsVidaBase){
        return this->ptsVidaBase=20;
    }
};

class Anao: public Personagem{
public:
    Anao(){
        cout << "Seu personagem e um anao" << endl;
    }

    int CalcDano(int danoBase){
        return this->danoBase=15;
    }

    int CalcPtsVida(int ptsVidaBase){
        return this->ptsVidaBase=120;
    }
};

class Elfo: public Personagem{
public:
    Elfo(){
    cout << "Seu personagem e um elfo" << endl;
    }

    int CalcDano(int danoBase){
        return this->danoBase=90;
    }

    int CalcPtsVida(int ptsVidaBase){
        return this->ptsVidaBase=90;
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
		
        cout <<"---------------------" << endl;
        cout <<"- Escolha uma raca: -" << endl;
        cout <<"- 1- Humano.        -" << endl;
        cout <<"- 2- Anao.          -" << endl;
        cout <<"- 3- Elfo.          -" << endl;
        cout <<"---------------------" << endl;
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
		cout << "Dano Total: " << criacao[i].CalcDano() << endl;
		cout << "Vida Total: " << criacao[i].CalcPtsVida() << endl;		
	}
}
