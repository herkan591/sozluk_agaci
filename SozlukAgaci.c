#include "stdlib.h"
#include "conio.h"
#include "stdio.h"

struct sozluk{
	char evethayir;
	struct sozluk *sonraki[256];
}*kok;
char kelime[100];int harf=-1;int ascii=0;char gecici[100];int sayac=0;

void ekle(struct sozluk *dugum);
//int ara(struct sozluk *dugum);
int ara(struct sozluk *dugum, char *metin);
void sonrakilerinulle(struct sozluk *dugum);
void sirala(struct sozluk *dugum);
void main(){
	kok=(struct sozluk*)malloc(sizeof(struct sozluk)*1);
	kok->evethayir='a';
	sonrakilerinulle(kok);
	while(1){
		harf=-1;
		printf("\nkelime : ");
		gets(kelime);
		printf("%s",kelime);
		if(kelime[0]=='0')break;
		ekle(kok);
	}
	printf("\nKelime arama islemleri baslatýldý");
	sirala(kok);
	
	while(1){
		harf=-1;
		printf("\naranacak kelime : ");
		gets(kelime);
		printf("%s",kelime);
		if(kelime[0]=='0')break;
		printf("\n%d",ara(kok,kelime));
	}
	
}

void ekle(struct sozluk *dugum){
	harf++;
	ascii=kelime[harf];
	if(kelime[harf]){//kelime harfleri bitene kadar
		if(dugum->sonraki[ascii]=='\0'){//yoksa olustur
			dugum->sonraki[ascii]=(struct sozluk*)malloc(sizeof(struct sozluk)*1);//bellekal
			dugum->sonraki[ascii]->evethayir='\0';//evethayiri güncelle
			sonrakilerinulle(dugum->sonraki[ascii]);//nulleme islemleri
			ekle(dugum->sonraki[ascii]);//kelime bitene kadar gönder
		}
		else{
			ekle(dugum->sonraki[ascii]);//kelime bitene kadar gönder
		}
	}else{
		dugum->evethayir='e';//kelime bittiyse bittiðini isaretle
	}
}

void sonrakilerinulle(struct sozluk *dugum){
	int i;
	for(i=0;i<256;i++){
		dugum->sonraki[i]='\0';
	}
}
int ara(struct sozluk *dugum, char *metin){
	int i=0;struct sozluk *gezen;gezen=dugum;int ascii;
	while(metin[i]){
		ascii=metin[i];
		if(gezen->sonraki[ascii]){
			gezen=gezen->sonraki[ascii];
			i++;
		}
		else{
		return 0;
		}
	}
	if(i==0||gezen->evethayir=='\0')return 0;
	return 1;
}
void sirala(struct sozluk *dugum){
	int i;
	for(i=0;i<256;i++){
		if(dugum->sonraki[i]){
			gecici[sayac]=i;
			sayac++;
			if(dugum->sonraki[i]->evethayir){//ekrana yazdir
				int k;
				printf("\n");
				for(k=0;k<sayac;k++)printf("%c",gecici[k]);
				printf("\n");
			}	
			sirala(dugum->sonraki[i]);
		} 
	}
	int g=-1;
	while(gecici[g+1]!='\0'){
		g++;
	}
	gecici[g]='\0';
	sayac--;
}











