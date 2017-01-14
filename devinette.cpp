#include<iostream>
#include<string>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main()
{
srand(time(NULL));
string tabLettreS,essai,affiche,rep,tabMots[10]={"hahahahaha","tyroide","rideau","egypte","sahara","ordinateur","chat","casserole","dromadaire","thomassin"};
int aleat=rand()%10,nbErreur=7,nbPass=0,tab[10],indice=0,indice1=0;
string bonMot=tabMots[aleat];
affiche.resize(bonMot.length());
char lettre,tabLettre[7];

for(int no=0;no<bonMot.length();no++)
{
    affiche[no]='-';
}
cout<<endl<<"Voila le mot a deviner :  "<<affiche<<endl;
do{
    cout<<endl<<"Tapez une lettre : "<<endl;
	cin>>lettre;
    tabLettreS+=lettre;
    tabLettreS+=" ";
    indice++;
	if(bonMot.find(lettre)!=string::npos)
	{
		cout<<"La lettre "<<lettre<<" est dans le mot a deviner"<<endl;
		nbPass++;
		for(int noPass=0;noPass<bonMot.length();noPass++)
            {
                if(lettre==bonMot[noPass])
                {
                    tab[indice]=noPass;
                    tabLettre[indice]=lettre;
                    indice++;
                }
            }
    }

	else
	{
		cout<<"La lettre "<<lettre<<" n'est pas dans le mot a deviner"<<endl;
		nbErreur--;

	}
	cout<<endl<<"Vous avez encore droit a "<<nbErreur<<" erreurs. Les lettres deja sorties sont : "<<tabLettreS<<endl<<"Voila le mot a deviner :  "<<endl<<endl;
	for(int nPass=0;nPass<bonMot.length();nPass++)
	{

	        for(int n=0;n<7;n++)
	        {
                if(bonMot[nPass]==tabLettre[n])
                {
                    affiche[nPass]=tabLettre[n];
                    //nbTest=1;
                }
            }
    }
    cout<<affiche<<endl<<endl;
    if(affiche!=bonMot)
    {
    cout<<"Voulez vous tenter de donner le mot ? Tapez oui pour le tenter "<<endl;
	cin>>rep;
	if(rep=="oui")
	{
		cout<<"quel est le mot? "<<endl;
		cin>>essai;
		if(essai!= bonMot)
		{
			cout<<"ce n'est pas le bon mot!!"<<endl;
			nbErreur--;
		}

	}
    }


}
while((nbErreur>0)&&(essai!=bonMot)&&(affiche!=bonMot));
if(nbErreur<=0)
{
    cout<<"Pendu ! Le mot a deviner etait : "<<bonMot;
}
else
{
    cout<<"Bravo vous avez trouvé le mot !";
}
}
