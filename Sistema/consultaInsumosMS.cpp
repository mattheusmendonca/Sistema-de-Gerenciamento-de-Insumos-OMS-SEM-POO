#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "consultaInsumosMS.h"

using namespace std;

int consultaInsumosMS()
{
  ifstream ip; //Cria uma vari�vel para apontar para o arquivo

  string line;

  //L� cada linha do arquivo "ip" e guarda em "line", uma linha a cada itera��o

  for(int i=0; i<3; i++){ // Esse loop ir� girar o dataset 3 vezes
    ip.open("estoqueMS.csv"); // Abrir�
    if(ip.is_open()){
      while (getline(ip, line)){
        // copia uma string ( no caso line ) e guarda em iss.
        istringstream iss(line);

        //poss�veis var�aveis dos insumos
        string insumo, nome, valorUni, quantidade, dataVenc, nomeFabri, tipoVac, quantDoses, interDose, tamDosagem, administracao, formOfertados, tipoEPI, descricaoEPI;

        // procura linhas v�lidas
        if(getline(iss, insumo, ',') && getline(iss, nome, ',') &&  getline(iss, valorUni, ',') && getline(iss, quantidade, ',') && getline(iss, dataVenc, ',') && getline(iss, nomeFabri, ',') && getline(iss, tipoVac,',') && getline(iss, quantDoses, ',') && getline(iss, interDose,',') && getline(iss, tamDosagem,',') && getline(iss, administracao,',') && getline(iss, formOfertados,',') && getline(iss, tipoEPI,',')&& getline(iss, descricaoEPI, ',')){

          /*
          char *endp = nullptr;
          long n = strtol(id.c_str(), &endp, 10);
          */

          if(i==0){
            //especifica linhas de vacina
            if(insumo == "Vacina" && tamDosagem == "NaN" && tipoEPI == "NaN"){
              cout << "Insumo: " << insumo << endl;
              cout << "Nome: " << nome << endl;
              cout << "Preco por unidade: " << valorUni << endl;
              cout << "Quantidade: " << quantidade << endl;
              cout << "Vencimento: " << dataVenc << endl;
              cout << "Fabricante: " << nomeFabri << endl;
              cout << "Tipo de vacina: " << tipoVac << endl;
              cout << "Quantidade de doses: " << quantDoses << endl;
              cout << "Per�odo de espera entre as doses: " << interDose << endl;
              cout << "\n----------------------------------\n";
            }
          }
          if(i==1){
            //especifica linhas de medicamento
            if(insumo == "Medicamento" && tipoVac == "NaN" && descricaoEPI == "NaN"){
              cout << "Insumo: " << insumo << endl;
              cout << "Nome: " << nome << endl;
              cout << "Preco por unidade: " << valorUni << endl;
              cout << "Quantidade: " << quantidade << endl;
              cout << "Vencimento: " << dataVenc << endl;
              cout << "Fabricante: " << nomeFabri << endl;
              cout << "Dosagem: " << tamDosagem << endl;
              cout << "Forma de administracao: " << administracao << endl;
              cout << "Forma de disponibiliza��o: " << formOfertados << endl;
              cout << "\n----------------------------------\n";
            }
          }

          if(i==2){
          //especifica linhas de EPI
            if(insumo == "EPI" && tamDosagem == "NaN" && tipoVac == "NaN"){
              cout << "Insumo: " << insumo << endl;
              cout << "Nome: " << nome << endl;
              cout << "Preco por unidade: " << valorUni << endl;
              cout << "Quantidade: " << quantidade << endl;
              cout << "Vencimento: " << dataVenc << endl;
              cout << "Fabricante: " << nomeFabri << endl;
              cout << "Tipo de EPI: " << tipoEPI << endl;
              cout << "Descricao do EPI: " << descricaoEPI << endl;
              cout << "\n----------------------------------\n";
            }
          }

        }
      }
      ip.close();
    }else{
      cout << "N�o foi poss�vel abrir o arquivo" << endl;
    }
  }
}
