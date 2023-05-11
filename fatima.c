#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#define max 10000

    
    typedef struct voiture
   {
	int idvoiture;
	char marque[15];
	char nomvoiture[15];
	char couleur[7];
	int nbplaces;
	int prixjour;
	char enlocation[4];
	}voiture;
	
		typedef struct date {
		int jour; 
		int mois;
		int annee;
	
	}date;
   
    typedef struct contratlocation{
    	float numcontrat; 
    	int idvoiture;
    	int idclient;
    	date debut;
    	date fin;
    	int cout;
	}contratlocation;
	typedef struct client{
		int idclient;
		char nom[20];
		char prenom[20];
		int cin;
		char adresse [15];
		int telephone;
	
	}client;
		void gestion_de_voitures(void);
    void menu_principal(void);
	 void retour(void){
	    	menu_principal();
		}
	 //l'affichage de la liste de voiture déja enregistrer
	 void afficher(void)
        { system("cls") ;
		  int c;
		   int fflush(FILE* file);
        	FILE *fich=fopen("voitures.txt","r");
        	
        	 voiture t;
        	 printf("la liste des voitures \n");
        	 printf("id voiture:\t marque:\t nom:\t  couleur:\t  nbplace:\t  prixjour:_\t  enlocation\n");
        	fseek(fich,0,SEEK_SET);
        	 do{
			 
      	       fscanf(fich,"%d %s %s %s %d %d %s\n",&t.idvoiture,t.marque,t.nomvoiture,t.couleur,&t.nbplaces,&t.prixjour,t.enlocation);
        	    fflush(stdin);
				printf("%d  \t\t",t.idvoiture);
        	 	printf("%s  \t\t",t.marque);
        	 	printf("%s  \t\t",t.nomvoiture);
        	 	printf("%s  \t\t",t.couleur);
        	 	printf("%d  \t\t",t.nbplaces);
        	 	printf("%d  \t\t",t.prixjour);
        	 	printf("%s\n",t.enlocation);
			 }while(!feof(fich));
	         fclose(fich);
	         printf("\nvous voulez rester au menu gestion de voitures (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_de_voitures();
        	  else
	          menu_principal();
		} 	 
		 
		//ajouter une voiture 	
	 
	 void ajout(){
	 	 system("cls");
	 	voiture nouveau;
	 	int id;
	 	int c;
	 	FILE *fichier=fopen("voitures.txt","a");
	 	 printf("entrer l'id du voiture\n");
		 scanf("%d",&id);
		 fflush(stdin); 
		 while(rech(id)==1){
		 	printf("cette voiture existe déja!!!!\n");
		 	printf("entrer un autre id de voiture\n");
		 	scanf("%d",&id);
		 }
		 nouveau.idvoiture=id;
	 	 printf("saisir maintenant les autres informations de voiture que vous voulez ajouter\n");
	 	 printf(" la marque\n ");
	 	 scanf("%s",nouveau.marque);
	     printf("nom de voiture \n");
	     scanf("%s",nouveau.nomvoiture);
	     printf("couleur \n");
	     scanf("%s",nouveau.couleur);
	     printf("nombre de place \n");
	     scanf("%d",&nouveau.nbplaces);
	     printf("le prix de jour \n");
	     scanf("%d",&nouveau.prixjour);
	     printf("la voiture est-il louée ?\n");
	     scanf("%s",nouveau.enlocation);
	     
	 	 fprintf(fichier,"\n%d %s %s %s %d %d %s",nouveau.idvoiture,nouveau.marque,nouveau.nomvoiture,nouveau.couleur,nouveau.nbplaces,nouveau.prixjour,nouveau.enlocation);	 	
	 	 
	     fclose(fichier);
	     printf("la voiture a ajoutée!!!\n");
	     printf("vous voulez rester au menu gestion de voiture (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_de_voitures();
        	  else
	          menu_principal();
	 }
//rechercher une voiture selon leur id sur la liste du voiture
    int rech (int num){
    	int fflush(FILE* file);
    	voiture t;
    	FILE *f=fopen("voitures.txt","r");
    	do{
    		fscanf(f,"%d %s %s %s %d %d %s\n",&t.idvoiture,t.marque,t.nomvoiture,t.couleur,&t.nbplaces,&t.prixjour,t.enlocation);
    		fflush(stdin);
    		if(t.idvoiture==num){
    		fclose(f);
    		return 1;}	
		}while(!feof(f));
		fclose(f);
		return 0;
	}
	 
	 
	 //modifier les informations d'une voiture déja enregistrer
	 void modifier()
	 {
	 	 system("cls");
         voiture t;;
        int id,choix;
	 	int c;
		printf("saisir l'id du voiture que voulez-vous modifier\n");
		scanf("%d",&id);
		fflush(stdin);
		if(rech(id)==1)
		{FILE* f=fopen("voitures.txt","r");
		 FILE* fich=fopen("voit.txt","a");
		 do{
		 	fscanf(f,"%d %s %s %s %d %d %s\n",&t.idvoiture,t.marque,t.nomvoiture,t.couleur,&t.nbplaces,&t.prixjour,t.enlocation);	
		   if(t.idvoiture==id)
			     {      
			     	do{
					 printf("qui ce que vous voulez modifier?\n");
			     	printf("  1:pour id de voiture\n  2:pour la marque\n  3:pour le nom de voiture\n  4:pour la couleur\n  5:pour le nombre de places\n  6:pour le prix\n  7:pour changer l'enlocation\n");
				    printf("\n      votre choix:");
				    scanf("%d",&choix);
				    }while(choix<0 ||choix>7);
				    switch(choix){
				    	case 1:
				    		printf("saisir le nouveau id de voiture\n");
				    		scanf("%f",&t.idvoiture);
				    		break;
				    	case 2:
				    		printf("saisir la nouvelle marque de voiture\n");
				    		scanf("%s",t.marque);
				    		break;
				    	case 3:
				    		printf("saisir le nouveau nom\n");
				    		scanf("%s",t.nomvoiture);
				    		break;
				    	case 4:
				    		printf("saisir la couleur\n");
				    		scanf("%s",t.couleur);
				    		break;
				    	case 5:
				    		printf("saisir le nombre de places\n");
				    		scanf("%d",&t.nbplaces);
				    		break;
				    	case 6:
				    		printf("saisir le nouveau prix\n");
				    		scanf("%d",&t.prixjour);
				    		break;
				    	case 7:
				    		printf("saisir le nouveau enlocation\n");
				    		scanf("%s",t.enlocation);
				    		break;
	     	
	 }
			}
    	fprintf(fich,"%d %s %s %s %d %d %s\n",t.idvoiture,t.marque,t.nomvoiture,t.couleur,t.nbplaces,t.prixjour,t.enlocation);
}       while(!feof(f));
		 fclose(f);
		 fclose(fich);
		 remove("voitures.txt");
		 rename("voit.txt","voitures.txt");
		 printf("modification est bien réussie!!!!\n");
	 }else
	 printf("cette voiture n'existe pas\n");
	 printf("vous voulez rester au menu gestion de voiture (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_de_voitures();
        	  else
	          menu_principal();
}
  //supprimer une voiture de la liste du voiture
	 void supprimer (){
	 	 system("cls");
	 	voiture t;
	 	int id;
	 	int c;
	 	printf("saisir l'id du voiture que voulez-vous supprimer\n");
		scanf("%d",&id);
		 while(rech(id)==0){
		 	printf("cette voiture n'existe pas!!!!\n");
		 	printf("entrer un autre id de voiture\n");
		 	scanf("%d",&id);
		 }
		 FILE* fichier=fopen("voitures.txt","r");
		 FILE* fich=fopen("voit.txt","a");
		 do{
		 	fscanf(fichier,"%d %s %s %s %d %d %s\n",&t.idvoiture,t.marque,t.nomvoiture,t.couleur,&t.nbplaces,&t.prixjour,t.enlocation);	
		   if(t.idvoiture!=id)
    	    fprintf(fich,"%d %s %s %s %d %d %s\n",t.idvoiture,t.marque,t.nomvoiture,t.couleur,t.nbplaces,t.prixjour,t.enlocation);
		}while(!feof(fichier));
			fclose(fichier);
			fclose(fich);
		     remove("voitures.txt");
		     rename("voit.txt","voitures.txt");
		 printf("la voiture a ete bien supprimée!!!!");
	 printf("\nvous voulez rester au menu gestion de voiture (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_de_voitures();
        	  else
	          menu_principal();
	 }
	 void gestion_client(void);
	    //afficher la liste du client
	 	 void afficher1(char * clients)
        {   system("cls") ;
		    int c;
		    int fflush(FILE* file);
        	FILE *fich=fopen("clients.txt","r");
        	
        	 client t;
        	 printf("la liste des clients \n");
        	fseek(fich,0,SEEK_SET);
        	printf("id client:\tnom client:\tprenom :\t\t cin:\t adresse:\ttelephone:\t\n");
        	 do{
			 fscanf(fich,"%d %s %s %d %s %d\n",&t.idclient,t.nom,t.prenom,&t.cin,t.adresse,&t.telephone);
        	    fflush(stdin);
				printf("%d \t\t",t.idclient);
        	 	printf("%s\t\t",t.nom);
        	 	printf("%s\t\t",t.prenom);
        	 	printf("%d\t\t",t.cin);
        	 	printf("%s\t\t",t.adresse);
        	 	printf("%d\t\t\n",t.telephone);
			 }while(!feof(fich));
	         fclose(fich);
	         printf("\nvous voulez rester au menu gestion de client (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_client();
        	  else
	          menu_principal();
	
		} 
		//rechercher un client selon leur id
		int rech1(int num){
			client nouveau;
			
			FILE *f=fopen("clients.txt","r");
			do{
			fscanf(f,"%d %s %s %d %s %d\n",&nouveau.idclient,nouveau.nom,nouveau.prenom,&nouveau.cin,nouveau.adresse,&nouveau.telephone);	
			if(nouveau.idclient==num){
				fclose(f);
				return 1;
			}
			}while(!feof(f));
			fclose(f);
			return 0;
			}
		//ajouter un client
		void ajout1(char *clients){
			 system("cls");
	    client nouveau;
	    int id;
	    int c;
	 	FILE *fichier=fopen("clients.txt","a");
	 	  printf("entrer l'id du client\n");
	 	  scanf("%d",&id);
	 	  while(rech(id)==1){
	 	  	printf("ce client existe déja!!!!\n");
	 	  	printf("saisir un autre id du client\n");
	 	  	scanf("%d",&id);
		   }
		   nouveau.idclient=id;
	 	 printf("saisir les autres informations de client que vous voulez ajouter\n");
	 	 printf("nom du client\n");
	 	 scanf("%s",nouveau.nom);
	 	 printf("prenom du client\n");
	 	 scanf("%s",nouveau.prenom);
	 	 printf("cin du client\n");
	 	 scanf("%d",&nouveau.cin);
	 	 printf("adresse du client\n");
	 	 scanf("%s",nouveau.adresse);
	 	 printf("numero du telephone\n");
	 	 scanf("%d",&nouveau.telephone);
	 	 
	 	 fprintf(fichier,"\n%d %s %s %d %s %d\n",nouveau.idclient,nouveau.nom,nouveau.prenom,nouveau.cin,nouveau.adresse,nouveau.telephone);	 	
	fclose(fichier);
	printf("client ajoutee!!!!\n");
	printf("vous voulez rester au menu gestion de client (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_client();
        	  else
	          menu_principal();
	}
	//modifier les informations d'un client déja enregistrer dans la liste du client
	 void modifier1(){
	 	 system("cls");
	 	client t;
        int id,choix;
        int c;
		printf("saisir l'id du client que voulez-vous modifier\n");
		scanf("%d",&id);
		fflush(stdin);
		if(rech1(id)==1){
	    	FILE* fichier=fopen("clients.txt","r");
		    FILE* fich=fopen("cli.txt","a");
		    do{
		     fscanf(fichier,"%d %s %s %d %s %d\n",&t.idclient,t.nom,t.prenom,&t.cin,t.adresse,&t.telephone);
	    	 if(t.idclient==id){
			     	do{
					 printf("qui ce que vous voulez modifier?\n");
			     	printf("  1:pour id de client\n  2:pour le nom de client\n  3:pour le prenom de client\n  4:pour le cin\n  5:pour l'adresse de client\n  6:pour le n°de telephone\n");
				    printf("\n      votre choix:");
				    scanf("%d",&choix);
				    }while(choix<0 ||choix>6);
				    switch(choix){
				    	case 1:
				    		printf("saisir le nouveau id de client\n");
				    		scanf("%f",&t.idclient);
				    		break;
				    	case 2:
				    		printf("saisir le nouveau nom\n");
				    		scanf("%s",t.nom);
				    		break;
				    	case 3:
				    		printf("saisir le nouveau prenom\n");
				    		scanf("%s",t.prenom);
				    		break;
				    	case 4:
				    		printf("saisir le cin\n");
				    		scanf("%d",&t.cin);
				    		break;
				    	case 5:
				    		printf("saisir l'adresse\n");
				    		scanf("%d",&t.adresse);
				    		break;
				    	case 6:
				    		printf("saisir le n°de telephone\n");
				    		scanf("%d",&t.telephone);
				    		break;
	     	
	 }
			}
		       
    	fprintf(fich,"\n%d %s %s %d %s %d\n",t.idclient,t.nom,t.prenom,t.cin,t.adresse,t.telephone);	 
	}while(!feof(fichier));
	fclose(fichier);
	fclose(fich);
	remove("clients.txt");
	rename("cli.txt","clients.txt");
	printf("modification a bien fait!!!!!\n");
  }else
     printf("ce client n'existe pas!!!!\n");
     printf("vous voulez rester au menu gestion de client (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_client();
        	  else
	          menu_principal();
	 }
	 //supprimer un client de la liste du client
	 void supprimer1 (){
	 	 system("cls");
	    client t;
	    int id;
	    int c;
	 	printf("saisir l'id du client que voulez-vous supprimer\n");
		scanf("%d",&id);
		while(rech1(id)==0){
			printf("ce client n'existe pas\n");
			printf("entrer un autre id de client\n");
			scanf("%d\n",&id);
		}
		FILE *f=fopen("clients.txt","r");
		FILE *fichier=fopen("cli.txt","a");
		do{
			fscanf(f,"%d %s %s %d %s %d\n",&t.idclient,t.nom,t.prenom,&t.cin,t.adresse,&t.telephone);
			if(t.idclient!=id)
    	         fprintf(fichier,"%d %s %s %d %s %d\n",t.idclient,t.nom,t.prenom,t.cin,t.adresse,t.telephone);	 
		        
	}while(!feof(f));
	fclose(f);
	fclose(fichier);
	remove("clients.txt");
	rename("cli.txt","clients.txt");
	     printf("client supprimee!!!!!\n");
		 printf("\nvous voulez rester au menu gestion de client (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      gestion_client();
        	  else
	          menu_principal();
	 }	 
	 //rechercher un contrat selon leur numéro 
	 int rech2 (float num){
    	int fflush(FILE* file);
    	contratlocation t;
    	FILE *f=fopen("contratslocations.txt","r");
    	do{
    		fscanf(f,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&t.numcontrat,&t.idvoiture,&t.idclient,&t.debut.jour,&t.debut.mois,&t.debut.annee,&t.fin.jour,&t.fin.mois,&t.fin.annee,&t.cout);
	 	         
    		fflush(stdin);
    		if(t.numcontrat==num){
    		fclose(f);
    		return 1;}	
		}while(!feof(f));
		fclose(f);
		return 0;
	}
	    //rechercher selon l'id de voiture enregistrer dans le contrat
	    int rech4 (int num){
    	int fflush(FILE* file);
    	contratlocation t;
    	FILE *f=fopen("contratslocations.txt","r");
    	do{
    		fscanf(f,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&t.numcontrat,&t.idvoiture,&t.idclient,&t.debut.jour,&t.debut.mois,&t.debut.annee,&t.fin.jour,&t.fin.mois,&t.fin.annee,&t.cout);
	 	         
    		fflush(stdin);
    		if(t.idvoiture==num){
    		fclose(f);
    		return 1;}	
		}while(!feof(f));
		fclose(f);
		return 0;
	} void location(void);
	    //visualiser un contrat
		void visualiser(char *contratslocations){
			 system("cls");
			float num;
			int c;
             contratlocation t;
			printf("donner le num de contrat que vous voulez visualiser:\n ");
			scanf("%f",&num);
			FILE* fichier1=fopen("contratslocations.txt","r");
	 	    
		        if(rech2(num)==1){
		      	do{
    		      fscanf(fichier1,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&t.numcontrat,&t.idvoiture,&t.idclient,&t.debut.jour,&t.debut.mois,&t.debut.annee,&t.fin.jour,&t.fin.mois,&t.fin.annee,&t.cout); 
    		      fflush(stdin);
    	        	if(t.numcontrat==num)
				 {
				 printf("num de contrat:%f\n",t.numcontrat);
				 printf("id de voiture:%d\n",t.idvoiture);
				 printf("id de client:%d\n",t.idclient);
				 printf("date de debut:%d/%d/%d\n",t.debut.jour,t.debut.mois,t.debut.annee);
				 printf("date de fin:%d/%d/%d\n",t.fin.jour,t.fin.mois,t.fin.annee);
				 printf("le cout:%d\n",t.cout);
			}
			 }while(!feof(fichier1));
			  fclose(fichier1);
		}
		  else
		   printf("ce num de contrat n'existe pas !!!!\n");
		printf("vous voulez rester au menu location (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      location();
        	  else
	          menu_principal();
	}
	int rech5(char* no,char* pre){
		client t;
		FILE* f=fopen("clients.txt","r");
      
	
			do{
			fscanf(f,"%d %s %s %d %s %d\n",&t.idclient,t.nom,t.prenom,&t.cin,t.adresse,&t.telephone);
			if(strcmp(t.nom,no)==0 && strcmp(t.prenom,pre)==0){
			return 1;
			fclose(f);	 
		    }
	}while(!feof(f));
	return 0;
	fclose(f);
		}
	
int cout(date deb,date fin,int prix){
	int nbjour,valdeb,valfin;
	valdeb=deb.jour+deb.mois*30+deb.annee*365;
	valfin=fin.jour+fin.mois*30+fin.annee*365;
	nbjour=valfin-valdeb;
	return(nbjour*prix);
	
}
		//louer une voiture disponible 
		    int louer (){
		    	 system("cls");
		   	client t;
		    char nom[50],prenom[50];
		   	int d,h=0;
		   	int trouve=1;
		   	voiture f,v;
		   	contratlocation c;
		   	FILE* f1=fopen("clients.txt","r");
		   	printf("entrer le nom et le prenom  de client:\n");
		   	scanf("%s %s",nom,prenom);
		   	if(rech5(nom,prenom)==1)
			printf("vous etes dans la liste des clients c'est bien!\n");
     		else{
	
		    	printf("enregistrer d'abord vos informationns a partir du menu gestion des clients\n");
			        return 0;
						}
			        fclose(f1);
			printf("saisir les informations de la voiture que vous voulez louer:\n ");
			printf("l'id de voiture:\n");
			scanf("%d",&v.idvoiture);
//		    printf(" la marque\n ");
//	 	    scanf("%s",v.marque);
//	        printf("nom de voiture \n");
//	        scanf("%s",v.nomvoiture);
//	        printf("couleur \n");
//	        scanf("%s",v.couleur);
//	        printf("nombre de place \n");
//	        scanf("%d",&v.nbplaces);
//	        printf("le prix de jour \n");
//	        scanf("%d",&v.prixjour);


		   	
			FILE* fich=fopen("voitures.txt","r");
			FILE* ff=fopen("voit.txt","a");
		do{
		  fscanf(fich,"%d %s %s %s %d %d %s\n",&f.idvoiture,f.marque,f.nomvoiture,f.couleur,&f.nbplaces,&f.prixjour,f.enlocation);
             if(f.idvoiture==v.idvoiture)
			 {
			 	if(strcmp(f.enlocation,"oui")==0){
				 
			 	printf("la voiture n'est pas disponible\n");
				 printf("vous voulez rester au menu location (tapez 1)??\n");
	         scanf("%d",&d);
        	 if(d==1)
		      location();
        	  else
	          menu_principal();}
			 	else {
				 
			 	strcpy(f.enlocation,"oui");
			 
			 	FILE* fichier=fopen("contratslocations.txt","a");
			 	printf("saisir les informations necessaires pour ajouter un nouveau contrat!! \n");
			 	
			 	printf("numcontrat\n");
			 	scanf("%f",&c.numcontrat);
		
			 	printf("id de client:\n");
			 	scanf("%d",&c.idclient);
			 	printf("date de debut:\n");
			 	scanf("%d/%d/%d",&c.debut.jour,&c.debut.mois,&c.debut.annee);
			 	printf("date de fin:\n");
			 	scanf("%d/%d/%d",&c.fin.jour,&c.fin.mois,&c.fin.annee);
			 	c.cout=cout(c.debut,c.fin,f.prixjour);
			fprintf(fichier,"\n%f %d %d  %d/%d/%d  %d/%d/%d   %d\n",c.numcontrat,v.idvoiture,c.idclient,c.debut.jour,c.debut.mois,c.debut.annee,c.fin.jour,c.fin.mois,c.fin.annee,c.cout);	 	
			 	fclose(fichier);
					 }			trouve=0;	
		
		}
		fprintf(ff,"%d %s %s %s %d %d %s\n",f.idvoiture,f.marque,f.nomvoiture,f.couleur,f.nbplaces,f.prixjour,f.enlocation);
	}   while(!feof(fich));
	fclose(fich);
	fclose(ff);
	remove("voitures.txt");
	rename("voit.txt","voitures.txt");
	  if(trouve==1){
	  
	      printf("la voiture demandée n'existe pas\n");
	      	printf("vous voulez rester au menu location (tapez 1)??\n");
	         scanf("%d",&d);
        	 if(d==1)
		      location();
        	  else
	          menu_principal();
		   }else{
	      printf("contrat est bien cree!!!\n");
		   	printf("vous voulez rester au menu location (tapez 1)??\n");
	         scanf("%d",&d);
        	 if(d==1)
		      location();
        	  else
	          menu_principal();
		   }
		   }
		   //retourner une voiture déja louée
		   void retourner (char*contratslocations,char* voitures,char* clients){
		   	 system("cls");
		    int id;
		    int c;
		    contratlocation t;
		    voiture f;
		   	printf("saisir l'id de la voiture retournee\n");
		   	scanf("%d",&id);
		   	FILE* fich=fopen("voitures.txt","r");
		   	FILE* F=fopen("voit.txt","a");
		   	do{
					fscanf(fich,"%d %s %s %s %d %d %s\n",&f.idvoiture,f.marque,f.nomvoiture,f.couleur,&f.nbplaces,&f.prixjour,f.enlocation);
			    if(f.idvoiture==id)
		        	strcpy(f.enlocation,"non");	 
				fprintf(F,"%d %s %s %s %d %d %s\n",f.idvoiture,f.marque,f.nomvoiture,f.couleur,f.nbplaces,f.prixjour,f.enlocation);     
		}while(!feof(fich));
		fclose(fich);
		fclose(F);
		remove("voitures.txt");
		rename("voit.txt","voitures.txt");
		   	FILE* fic=fopen("contratslocations.txt","r");
		   	FILE* fichier=fopen("contr.txt","a");
		   	do{
		   		    fscanf(fic,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&t.numcontrat,&t.idvoiture,&t.idclient,&t.debut.jour,&t.debut.mois,&t.debut.annee,&t.fin.jour,&t.fin.mois,&t.fin.annee,&t.cout); 
		   		     if(t.idvoiture!=id)
		   		     fprintf(fichier,"%f %d %d %d/%d/%d %d/%d/%d %d \n",t.numcontrat,t.idvoiture,t.idclient,t.debut.jour,t.debut.mois,t.debut.annee,t.fin.jour,t.fin.mois,t.fin.annee,t.cout); 
			   }while(!feof(fic));
		   	fclose(fic);
		   	fclose(fichier);
		   	remove("contratslocations.txt");
		   	rename("contr.txt","contratslocations.txt");
		   	printf("la voiture est retournee  \n");
		   	printf("\nvous voulez rester au menu location (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      location();
        	  else
	          menu_principal();
		   }
		   //supprimer un contrat
		   void supprim (char* contratslocations){
		   	 system("cls");
		   	contratlocation  t;
		   	int id;
		   	int c;
		   	printf("entrer l'id de voiture rendee!!!\n");
		   	scanf("%d",&id);
		  FILE* fic=fopen("contratslocations.txt","r");
		   	FILE* fichier=fopen("contr.txt","a");
		   	if(rech4(id)==1){
			   
		   	do{
		   		    fscanf(fic,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&t.numcontrat,&t.idvoiture,&t.idclient,&t.debut.jour,&t.debut.mois,&t.debut.annee,&t.fin.jour,&t.fin.mois,&t.fin.annee,&t.cout); 
		   		     if(t.idvoiture!=id)
		   		     fprintf(fichier,"%f %d %d %d/%d/%d %d/%d/%d %d \n",t.numcontrat,t.idvoiture,t.idclient,t.debut.jour,t.debut.mois,t.debut.annee,t.fin.jour,t.fin.mois,t.fin.annee,t.cout); 
			   }while(!feof(fic));
		   	fclose(fic);
		   	fclose(fichier);
		   	remove("contratslocations.txt");
		   	rename("contr.txt","contratslocations.txt");
			   printf("le contrat est bien supprimeé!!!\n");
			   }
		   	else
		   	 printf("le contrat n'existe pas!!!\n");
		   	printf("\nvous voulez rester au menu location (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      location();
        	  else
	          menu_principal();
		   }
		   //modifier un contrat
		void modif(){
			 system("cls");
			int id;
			int choix;
			int c;
			contratlocation t;
			printf("saisir l'id de voiture que vous voulez modifier\n");
			scanf("%d",&id);
			fflush(stdin);
			if(rech4(id)==1){
				 	 FILE* fichier=fopen("contratslocations.txt","r");
		             FILE* fich=fopen("cont.txt","a");
				 do{	
				 fscanf(fichier,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&t.numcontrat,&t.idvoiture,&t.idclient,&t.debut.jour,&t.debut.mois,&t.debut.annee,&t.fin.jour,&t.fin.mois,&t.fin.annee,&t.cout);                                                                                                         
			    
				 if(t.idvoiture==id)
			     {      
			     	do{
					 printf("qui ce que vous voulez modifier?\n");
			     	printf("1:pour num de contrat\n2:pour id de voiture\n3:pour id de client\n4:pour la date de debut\n5:pour la date de fin\n6:pour le cout\n");
				    printf("votre choix:");
				    scanf("%d",&choix);
				    }while(choix<0 ||choix>6);
				    switch(choix){
				    	case 1:
				    		printf("saisir le nouveau num de contrat\n");
				    		scanf("%f",&t.numcontrat);
				    		break;
				    	case 2:
				    		printf("saisir le nouveau id de voiture\n");
				    		scanf("%d",&t.idvoiture);
				    		break;
				    	case 3:
				    		printf("saisir le nouveau id de clients\n");
				    		scanf("%d",&t.idclient);
				    		break;
				    	case 4:
				    		printf("saisir le nouveau date de debut\n");
				    		scanf("%d/%d/%d",&t.debut.jour,&t.debut.mois,&t.debut.annee);
				    		break;
				    	case 5:
				    		printf("saisir le nouveau date de fin\n");
				    		scanf("%d/%d/%d",&t.fin.jour,&t.fin.mois,&t.fin.annee);
				    		break;
				    	case 6:
				    		printf("saisir le nouveau cout\n");
				    		scanf("%d/%d/%d",&t.cout);
				    		break;
					}
				 }
			fprintf(fich,"%f %d %d %d/%d/%d %d/%d/%d %d \n",t.numcontrat,t.idvoiture,t.idclient,t.debut.jour,t.debut.mois,t.debut.annee,t.fin.jour,t.fin.mois,t.fin.annee,t.cout); 	 
			}while(!feof(fichier));
			fclose(fichier);
			fclose(fich);
			remove("contratslocations.txt");
			rename("cont.txt","contratslocations.txt");
		printf("modification bien faite!!!\n");
           }else 
           printf("le contrat n'existe pas!!\n");
        	printf("vous voulez rester au menu location (tapez 1)??\n");
	         scanf("%d",&c);
        	 if(c==1)
		      location();
        	  else
	          menu_principal();
	  }
		   //menu gestion de voiture 
		void gestion_de_voitures(void){
			 system("cls");
			int choix;
		printf(" \n                           \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf(" \n                           \xb3 gestion des voiture   \xb3");
		printf(" \n                           \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		do{
		
		printf("\n                  \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
		printf("\n                  \xba                                              \xba");
		printf("\n                  \xba   liste des voitures ..........1             \xba");
		printf("\n                  \xba   ajouter voiture .............2             \xba");
		printf("\n                  \xba   modifier voiture.............3             \xba");
		printf("\n                  \xba   supprimer voiture............4             \xba");
		printf("\n                  \xba   retour............ ..........5             \xba");
		printf("\n                  \xba                                              \xba");
		printf("\n                  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	    printf("\n\n                       votre choix:  ");
	    scanf("%d",&choix);
	}while(choix<1||choix>5);
	switch(choix){
		case 1:
			afficher();
			break;
		case 2:
			ajout();
			break;
		case 3:
			modifier();
			break;
		case 4:
			supprimer("voitures.txt");
			break;
		case 5:
			retour();
			break;
		default :
		 printf("erreur");
		 
	}
}
   //menu gestion de client
	void gestion_client(void){
		 system("cls");
		int choix;
		printf(" \n                            \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf(" \n                            \xb3 gestion des clients   \xb3");
		printf(" \n                            \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		do{
		
		printf("\n                   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
		printf("\n                   \xba                                              \xba");
		printf("\n                   \xba   liste des clients; ..........1             \xba");
		printf("\n                   \xba   ajouter client...............2             \xba");
		printf("\n                   \xba   modifier client..............3             \xba");
		printf("\n                   \xba   supprimer client.............4             \xba");
		printf("\n                   \xba   retour............ ..........5             \xba");
		printf("\n                   \xba                                              \xba");
		printf("\n                   \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	    printf("\n\n                       votre choix:  ");
	    scanf("%d",&choix);
	}while(choix<1||choix>5);
	switch(choix){
		case 1:
			afficher1("clients.txt");
			break;
		case 2:
			ajout1("clients.txt");
			break;
		case 3:
			modifier1("clients.txt");
			break;
		case 4:
			supprimer1("clients.txt");
			break;
		case 5:
			retour();
			break;
		default :
		 printf("erreur");
		 
	}
}
  //menu location
  void location(void){
  	 system("cls");
  int choix;
		printf(" \n                           \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf(" \n                           \xb3  location d'une voiture  \xb3");
		printf(" \n                           \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		do{
		
		printf("\n                  \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
		printf("\n                  \xba                                              \xba");
		printf("\n                  \xba   visualiser contrat ..........1             \xba");
		printf("\n                  \xba   louer voiture ...............2             \xba");
		printf("\n                  \xba   retourner voiture............3             \xba");
		printf("\n                  \xba   modifier contrat.............4             \xba");
		printf("\n                  \xba   supprimer contrat............5             \xba");
		printf("\n                  \xba   retour............ ..........6             \xba");
		printf("\n                  \xba                                              \xba");
		printf("\n                  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	    printf("\n\n                 votre choix:  ");
	    scanf("%d",&choix);
	}while(choix<1||choix>7);
	switch(choix){
		case 1:
			visualiser("contratslocations.txt");
			break;
		case 2:
			louer("contratslocations.txt","voitures.txt","clients.txt");
   			break;
		case 3:
			retourner("contratslocations.txt","voitures.txt","clients.txt");
			break;
		case 4:
			modif("contratslocations.txt");
			break;
		case 5:
			supprim("contratslocations.txt");
			break;
		case 6:
			retour();
			break;
		default :
		 printf("erreur");
		 
	}
}
  //quitter le programme
    void quitter(){
	exit(1);}
	
	//menu principale 
	 void menu_principal(void){
	 	 system("cls");
	 	int choix;
		printf(" \n                          \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf(" \n                          \xb3 menu principal        \xb3");
		printf(" \n                          \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		do{
		
		printf("\n                 \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
		printf("\n                 \xba                                              \xba");
		printf("\n                 \xba   location.......... ..........1             \xba");
		printf("\n                 \xba   gestion voiture..............2             \xba");
		printf("\n                 \xba   gestion client...............3             \xba");
		printf("\n                 \xba   quitter......................4             \xba");
		printf("\n                 \xba                                              \xba");
		printf("\n                 \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	    printf("\n\n                     votre choix:  ");
	    scanf("%d",&choix);
	}while(choix<1||choix>4);
	switch(choix){
		case 1:
			location();
			break;
		case 2:
			gestion_de_voitures();
			break;
		case 3:
			gestion_client();
			break;
		case 4:
			quitter();
			break;
		
		default :
		 printf("erreur");
		 
}
	 }
	 int main(){
		  menu_principal();
		   return 0;
}	 
	 
	 
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
