/* Código muito antigo que fiz com um amigo. Provavelmente o primeiro código de verdade que eu fiz.
 * É praticamente 2k linhas de copy and paste sendo que algumas funções resolveriam :P.
 * Pura nostalgia, preciso guardar isso.
 */
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>

//gotoxy(coluna,linha)
char nome[10];
int hability, energy, luck, enemy, apos=25;

void menuf()
{
  int x=2,y=2;
  clrscr();
  textcolor(4);
  textbackground(0);
  gotoxy(1,1);
  cprintf("\xc9");
  while(x<78)
  {
    gotoxy(x,1);
    cprintf("\xcd");
    x++;
  }
  gotoxy(1,79);
  cprintf("\xbb");
  while(y<15)
  {
    gotoxy(1,y);
    cprintf("\xba");
    y++;
  }
  y=2;
  while(y<15)
  {
    gotoxy(78,y);
    cprintf("\xba");
    y++;
  }
  gotoxy(x,y);
  cprintf("\xbc");
  gotoxy(1,y);
  cprintf("\xc8");
  x=2;
  while(x<78)
  {
    gotoxy(x,y);
    cprintf("\xcd");
    x++;
  }
  y=2;

  while(y<15)
  {
    x=2;
    while(x<78)
    {
      gotoxy(x,y);
      cprintf(" ");
      x++;
    }
    y++;
  }


}

void menun()
{
  int x=2,y=2;
  clrscr();
  textcolor(6);
  textbackground(0);
  gotoxy(1,1);
  cprintf("\xc9");
  while(x<78)
  {
    gotoxy(x,1);
    cprintf("\xcd");
    x++;
  }
  gotoxy(1,79);
  cprintf("\xbb");
  while(y<23)
  {
    gotoxy(1,y);
    cprintf("\xba");
    y++;
  }
  y=2;
  while(y<23)
  {
    gotoxy(78,y);
    cprintf("\xba");
    y++;
  }
  gotoxy(x,y);
  cprintf("\xbc");
  gotoxy(1,y);
  cprintf("\xc8");
  x=2;
  while(x<78)
  {
    gotoxy(x,y);
    cprintf("\xcd");
    x++;
  }
  y=2;

  while(y<23)
  {
    x=2;
    while(x<78)
    {
      gotoxy(x,y);
      cprintf(" ");
      x++;
    }
    y++;
  }


}


int dados1()
{
srand(time(NULL));
long x,y;
x=rand()%6+1;

return (x);
}

int dados2()
{
srand(time(NULL));
long x,y;
x=rand()%6+1;
delay(450);
y=rand()%6+1;
while(y==x)
{
 y=rand()%6+1;
}
x=x+y;
return (x);
}



int fight()
{
    int power, enemypower, enemyhabil, enemyenergy;
    int g=5;

    switch(enemy)
    {
	   case 1:
	   //mumia
	   menuf();
	   g=5;
       gotoxy(2,2);
	   cout<<"Ent""\xC6""o "<<nome<<" e a Mumia se atacam";
	   enemyhabil=10;enemyenergy=11;
	   while(energy>0&&enemyenergy>0)
	   {
	       power=dados2()+hability;
	       gotoxy(2,3);
	       cout<<"A sua forca ""\x82"" "<<power<<"   ";
	       delay(500);
	       enemypower=enemyhabil+dados2();
	       gotoxy(2,4);
	       cout<<"A forca da Mumia ""\x82"" "<<enemypower<<"   ";

	       if(power>enemypower)
		  {
		       enemyenergy=enemyenergy-2;
		       gotoxy(2,g);g++;
		       cout<<"O seu inimigo sofreu 2 pontos de dano";
		  }
	       else
		  {
		       energy=energy-2;
		       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" acaba de sofrer 2 pontos de dano";
		  }
	       delay(500);
	       if(g==15)
	       {
		       clrscr();
		       menuf();
		       g=5;
	       }
	   }
	   if(energy<0)
	     {
               gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" foi derrotado pelo monstro e agora sua alma vagar""\xA0"" ";
		       gotoxy(2,g);g++;
		       cout<<"eternamente como uma das almas condenadas desse labirinto.";
		 }
	   else
	     {
		       gotoxy(2,g);g++;
               cout<<"O monstro foi derrotado";
	     }
	   break;


	   case 2:
	   //Serpente
	   menuf();
	   g=5;
	   gotoxy(2,2);
	   cout<<"Entao "<<nome<<" e a Serpente se atacam";
	   enemyhabil=6;enemyenergy=7;
	   while(energy>0&&enemyenergy>0)
	   {

	       power=dados2()+hability;
	       gotoxy(2,3);
	       cout<<"A sua forca ""\x82"" "<<power;
	       delay(500);
	       enemypower=enemyhabil+dados2();
	       gotoxy(2,4);
	       cout<<"A forca da Serpente ""\x82"" "<<enemypower;
		       if(power>enemypower)
		  {
		       enemyenergy=enemyenergy-2;
		       gotoxy(2,g);g++;
		       cout<<"O seu inimigo sofreu 2 pontos de dano";
		  }
	       else
		  {
		       energy=energy-2;
		       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" acaba de sofrer 2 pontos de dano";
		  }
	       delay(500);
	       if(g==15)
	       {
               clrscr();
               menuf();
               g=5;
           }
	   }
	   if(energy<0)
	     {
		       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" foi derrotado pelo monstro e agora sua alma vagar""\xA0"" ";
		       gotoxy(2,g);g++;
		       cout<<"eternamente como uma das almas condenadas desse labirinto.";
         }
	   else
	     {
		       gotoxy(2,g+1);g++;
               cout<<"O monstro foi derrotado";
	     }
	   break;


	   case 3:
	   //Calacorn
	   menuf();
	   g=5;
       gotoxy(2,2);
	   cout<<"Ent""\xC6""o "<<nome<<" e o Calacorm se atacam";
	   enemyhabil=9;enemyenergy=8;
	   while(energy>0&&enemyenergy>0)
	   {
	       power=dados2()+hability;
	       gotoxy(2,3);
	       cout<<"A sua forca ""\x82"" "<<power;
	       delay(500);
	       enemypower=enemyhabil+dados2();
	       gotoxy(2,4);
	       cout<<"A forca do Calacorm ""\x82"" "<<enemypower;
	       if(power>enemypower)
		  {
		       enemyenergy=enemyenergy-2;
		       gotoxy(2,g);g++;
		       cout<<"O seu inimigo sofreu 2 pontos de dano";
		  }
	       else
		  {
		       energy=energy-2;
		       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" acaba de sofrer 2 pontos de dano";
		  }
	       delay(500);
	       if(g==15)
	       {
		       clrscr();
		       menuf();
		       g=5;
	       }
	   }
	   if(energy<0)
	     {
               gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" foi derrotado pelo monstro e agora sua alma vagar""\xA0"" ";
		       gotoxy(2,g);g++;
		       cout<<"eternamente como uma das almas condenadas desse labirinto.";
		 }
	   else
	     {
		       gotoxy(2,g);g++;
               cout<<"O monstro foi derrotado";
	     }
	   break;


	   case 4:
	   //Bear
	   menuf();
	   g=5;
       gotoxy(2,2);
	   cout<<"Ent""\xC6""o "<<nome<<" e o Nandi Bear se atacam";
	   enemyhabil=9;enemyenergy=11;
	   while(energy>0&&enemyenergy>0)
	   {
	       power=dados2()+hability;
	       gotoxy(2,3);
	       cout<<"A sua forca ""\x82"" "<<power;
	       delay(500);
	       enemypower=enemyhabil+dados2();
	       gotoxy(2,4);
	       cout<<"A for""\x87""a do Nandi Bear ""\x82"" "<<enemypower;
	       if(power>enemypower)
		  {
		       enemyenergy=enemyenergy-2;
		       gotoxy(2,g);g++;
		       cout<<"O seu inimigo sofreu 2 pontos de dano";
		  }
	       else
		  {
		       energy=energy-2;
		       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" acaba de sofrer 2 pontos de dano";
		  }
	       delay(500);
	       if(g==15)
	       {
		       clrscr();
		       menuf();
		       g=5;
	       }
	   }
	  if(energy<0)
	     {
               gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" foi derrotado pelo monstro e agora sua alma vagar""\xA0"" ";
		       gotoxy(2,g);g++;
		       cout<<"eternamente como uma das almas condenadas desse labirinto.";
		 }
	   else
	     {
		       gotoxy(2,g);g++;
               cout<<"O monstro foi derrotado";
	     }
	   break;


	   case 5:
	   //Cerberus
	   menuf();
	   g=5;
       gotoxy(2,2);
	   cout<<"Ent""\xC6""o "<<nome<<" e o Cerberus se atacam";
	   enemyhabil=6;enemyenergy=7;
	   while(energy>0&&enemyenergy>0)
	   {
	       power=dados2()+hability;
	       gotoxy(2,3);
	       cout<<"A sua for""\x87""a ‚ "<<power;
	       delay(500);
	       enemypower=enemyhabil+dados2();
	       gotoxy(2,4);
	       cout<<"A for""\x87""a do Cerberus ""\x82"" "<<enemypower;
	       if(power>enemypower)
		  {
		       enemyenergy=enemyenergy-2;
		       gotoxy(2,g);g++;
		       cout<<"O seu inimigo sofreu 2 pontos de dano";
		  }
	       else
		  {
		       energy=energy-2;
		       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" acaba de sofrer 2 pontos de dano";
		  }
	       delay(500);
	       if(g==15)
	       {
		       clrscr();
		       menuf();
		       g=5;
	       }
	   }
	   if(energy<0)
	     {
	       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" foi derrotado pelo monstro e agora sua alma vagar""\xA0"" ";
		       gotoxy(2,g);g++;
		       cout<<"eternamente como uma das almas condenadas desse labirinto.";
		 }
	   else
	     {
		       gotoxy(2,g);g++;
	       cout<<"O monstro foi derrotado";
	     }
	   break;


	   case 6:
	   //zumbi
	   menuf();
	   g=5;
       gotoxy(2,2);
	   cout<<"Ent""\xC6""o "<<nome<<" e o Zumbi se atacam";
	   enemyhabil=6;enemyenergy=6;
	   while(energy>0&&enemyenergy>0)
	   {

	       power=dados2()+hability;
	       gotoxy(2,3);
	       cout<<"A sua for""\x87""a ""\x82"" "<<power;
	       delay(500);
	       enemypower=enemyhabil+dados2();
	       gotoxy(2,4);
	       cout<<"A for""\x87""a do Zumbi ""\x82"" "<<enemypower;
	       if(power>enemypower)
		  {
		       enemyenergy=enemyenergy-2;
		       gotoxy(2,g);g++;
		       cout<<"O seu inimigo sofreu 2 pontos de dano";
		  }
	       else
		  {
		       energy=energy-2;
		       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" acaba de sofrer 2 pontos de dano";
		  }
		  delay(500);
		  if(g==15)
	       {
		       clrscr();
		       menuf();
		       g=5;
	       }
	   }
	   if(energy<0)
	     {
	       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" foi derrotado pelo monstro e agora sua alma vagar""\xA0"" ";
		       gotoxy(2,g);g++;
		       cout<<"eternamente como uma das almas condenadas desse labirinto.";
		 }
	   else
	     {
		       gotoxy(2,g);g++;
	       cout<<"O monstro foi derrotado";
	     }
	   break;


	   case 7:
	   //Rei aranha
	   menuf();
	   g=5;
       gotoxy(2,2);
	   cout<<"Ent""\xC6""o "<<nome<<" e o Rei Aranha se atacam";
	   enemyhabil=10;enemyenergy=16;
	   while(energy>0&&enemyenergy>0)
	   {
	     power=dados2()+hability;
	     gotoxy(2,3);
	     cout<<"A sua for""\x87""a ""\x82"" "<<power;
	     delay(500);
	     enemypower=enemyhabil+dados2();
	     gotoxy(2,4);
	     cout<<"A for""\x87""a do Rei Aranha ""\x82"" "<<enemypower;
	     if(power>enemypower)
		 {
		      enemyenergy=enemyenergy-2;
		      gotoxy(2,g);g++;
		      cout<<"O seu inimigo sofreu 2 pontos de dano";
         }
	     else
		 {
		      energy=energy-2;
		      gotoxy(2,g);g++;
		      cout<<"Voc""\x88"" acaba de sofrer 2 pontos de dano";
		 }
		 delay(500);
		 if(g==15)
	     {
		      clrscr();
		      menuf();
		      g=5;
	     }
	   }
	   if(energy<0)
	     {
	       gotoxy(2,g);g++;
		       cout<<"Voc""\x88"" foi derrotado pelo monstro e agora sua alma vagar""\xA0"" ";
		       gotoxy(2,g);g++;
		       cout<<"eternamente como uma das almas condenadas desse labirinto.";
         }
	   else
	     {
		       gotoxy(2,g);g++;
	       cout<<"O monstro foi derrotado";
	     }
	}
    return (energy);
}

int main()
{
     char go;
     int g=2, op, axe=0, colar=0, bolsa=0, tocha=0, ouro=10, krystalkey=0;
     int brokenseal=0, kinghorn=0;
     int aposent1=0, aposent2=0, aposent3=0, aposent4=0, aposent5=0, aposent6=0;
     int aposent8=0, aposent13=0, aposent14=0, aposent15=0, aposent16=0;
     int aposent17=0, arca=0, Nandi=0;
     diadeheroi:{}
     clrscr();
     gotoxy(19,10);
     textcolor(3);
     cprintf("DIA DE HEROI");delay(1450);
     gotoxy(2,17);
     cprintf("Aperte:");delay(500);
     gotoxy(2,18);
     cprintf("C para ir para os cr""\x82""ditos");delay(500);
     gotoxy(2,19);
     cprintf("S para sair do jogo");delay(500);
     gotoxy(2,20);
     cprintf("Ou qualquer outra para iniciar o jogo");delay(500);
     go=getch();
     if(go=='c'||go=='C')
     {
        clrscr();
        menun();
        g=2;
        gotoxy(15,g);g++;delay(500);
        cout<<" ***CREDITOS FINAIS*** ";
        gotoxy(2,g);g++;delay(500);
        cout<<"Esses creditos s""\xC6""o para agradecer aos que tanto colaboraram para ";
        gotoxy(2,g);g++;delay(500);
        cout<<"que esse trabalho fosse concluido com sucesso e destreza. ";
        gotoxy(2,g);g++;delay(500);
        cout<<"Rodrigo: Programou que nem um louco e ta morrendo de dor no pulso.";
        gotoxy(2,g);g++;delay(500);
        cout<<"William: Construiu uma historia digna de um grande RPG com paciencia ";
	gotoxy(2,g);g++;delay(500);
        cout<<"e for""\x87""a de vontade. ";
        gotoxy(2,g);g++;delay(500);
        cout<<"A ambos que quase se mataram nesse trabalho de tanto odio e que ";
        gotoxy(2,g);g++;delay(500);
        cout<<"perderam horas e mais horas de sono para que ele ficasse bem feito ";
        gotoxy(2,g);g++;delay(500);
        cout<<"e sem servi""\x87""os domin""\xA2""s ";
        gotoxy(2,g);g++;delay(500);
        cout<<"Igor: Imprimiu... nada mais, serviria muito bem como um peso de ";
        gotoxy(2,g);g++;delay(500);
        cout<<"papel. ";
        gotoxy(2,g);g++;delay(500);
        cout<<"Fabricio: Nem peso de papel serve, n""\xC6""o fez nada mesmo ";
        gotoxy(2,22);g++;delay(500);
        cout<<"Aperte qualquer tecla para voltar ao menu anterior";
        go=getch();
        goto diadeheroi;
     }
     if(go=='s'||go=='S')
     {goto fimmesmo;}
     g=2;
     clrscr();
     menun();
     textcolor(7);
     //pr""\xA2""logo
     gotoxy(20,g);g++;
     cout<<" ***DIA DE HEROI*** ";
     gotoxy(2,g);g++;
     cout<<"Esta aventura acontece no fundo de um po""\x87""o antigo,onde h\xA0 muito ";
     gotoxy(2,g);g++;
     cout<<"tempo nobres e principes costumavam vir jogar suas moedas e fazer ";
     gotoxy(2,g);g++;
     cout<<"seus pedidos. Todo esse ouro era coletado no fundo do po""\x87""o. Quando o ";
     gotoxy(2,g);g++;
     cout<<"po""\x87""o secou, ca""\x87""adores de tesouros vieram de toda parte esperando ";
     gotoxy(2,g);g++;
     cout<<"encontrar riquezas.Mas, quando alcan""\x87""avam o po""\x87""o, eles descobriam ";
     gotoxy(2,g);g++;
     cout<<"que a busca que tinham diante de si era muito mais perigosa do que ";
     gotoxy(2,g);g++;
     cout<<"jamais haviam imaginado...";
     gotoxy(2,g);g++;
     cout<<"Voc""\x88"" ouviu falar dessa not""\xA1""cia de um po""\x87""o antigo que poderia ";
     gotoxy(2,g);g++;
     cout<<"armazenar um grande tesouro devido a seu passado. Voc""\x88"" est""\xA0"" ";
     gotoxy(2,g);g++;
     cout<<"treinando para ser um cavaleiro da guarda do rei, e tem coragem ";
     gotoxy(2,g);g++;
     cout<<"o suficiente para lutar contra o que for preciso para que voc""\x88"" ";
     gotoxy(2,g);g++;
     cout<<"possa crescer na vida, por esse motivo voc""\x88"" decidiu preparar sua ";
     gotoxy(2,g);g++;
     cout<<"mochila, coloca-la nas costas, ir at\x82 o po""\x87""o e pegar o tesouro.";
     delay(1000);
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     //fim do prologo
     clrscr();menun();g=2;
     gotoxy(20,g);g++;
     cout<<" ***DIA DE HEROI*** ";
     gotoxy(2,g);g++;
     cout<<"Chegando ao vilarejo onde se encontra o po""\x87""o voc""\x88"" \x82 abordado.";
     gotoxy(2,g);g++;
     cout<<"Soldado local:";
     gotoxy(2,g);g++;
     cout<<"Apresente-se guerreiro.";
     gotoxy(2,g);g++;
     cin>>nome;
     if(nome[0]=='M'&&nome[1]=='o'&&nome[2]=='s'&&nome[3]=='t'&&nome[4]=='i'&&nome[5]=='s')
     {
     g++;gotoxy(2,g);g++;
     cout<<"Soldado :Poxa cara voc""\x88"" ""\x82"" mesmo o "<<nome<<".";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Caramba eim voc""\x88"" programa pra caramba viu...";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :conseguiu terminar esse trabalho sem a ajuda de alguns elementos";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Agente faz o que ""\x82"" necessario ... fazer o que";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :voc""\x88"" vai entrar no po""\x87""o pra pegar o tesouro?";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Vou sim.";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Sera que ""\x82"" muito perigoso l""\xA0"" dentro?";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Ah fica tranquilo que voc""\x88"" ""\x82"" bom pra caramba e vai ser facil";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :""\x90"" s""\xA2"" n""\xC6""o se preocupar com o algum trabalho que tudo fica ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :simples.E mesmo porque o Fabricio e o Igor n""\xC6""o vao atrapalhar.";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Cara, realmente.E isso ""\x82"" um alivio.Vo indo l""\xA0"". H""\xA0"" bra""\x87""os!";
     goto poscheat;
     }
     if(nome[0]=='F'&&nome[1]=='a'&&nome[2]=='b'&&nome[3]=='r'&&nome[4]=='i'&&nome[5]=='c'&&nome[6]=='i'&&nome[7]=='o')
     {
     g++;gotoxy(2,g);g++;
     cout<<"Soldado :Ah n""\xC6""o acredito. O Ti Rango por aqui... que droga!!!";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Como anda a vida? fazendo nada como sempre?";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Fiquei sabendo que voc""\x88"" nem ajudou no trabalho de C++";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Ah meu, eu fiquei pesquisando o trabalho de Kalango e n...";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :T""\xA0"" T""\xA0"" T""\xA0"" eu sei que voc""\x88"" vai se lamentar e reclamar agora.";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Pô mais s""\xA2"" porque eu n""\xC6""o fiz nada, voc""\x88"" vai ficar tirando .";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :uma com a minha cara?";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Voc""\x88"" ""\x82"" muito pregui""\x87""oso n""\xC6""m fez nada e ainda quer que eu";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :elogie? Vai trabalhar e n""\xC6""o me enche a paciencia!";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Olha o Igor ta te chamando l""\xA0"".";
     gotoxy(2,g);g++;delay(250);
     cout<<"Igor :Ei cara olha essa fase do Mario que legal. ""\x82"" aqui perto do po""\x87""o.";
     goto poscheat;
     }
     if(nome[0]=='I'&&nome[1]=='g'&&nome[2]=='o'&&nome[3]=='r')
     {
     gotoxy(2,g);g++;
     cout<<"Soldado :Putz...O igor noooooooooooo!!!";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Voc""\x88"" n""\xC6""o faz nada mesmo hein...Nem ajudou a contruir esse trabalho";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :S""\xA2"" por que fez o trabalho do Reiniti acha que pode jogar esse?";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Siiileeenciioooooooowww!!";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Taaa bom mas n""\xC6""o se irrite!! O que procura aqui?";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :To procurando o po""\x87""o dos desejos";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Aaaaaa...O po""\x87""o fica la na frente!!";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Que bom mesmo que disse, por que tudo fica para mim fazer...";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :os caras mesmo n""\xC6""o fazem nada...";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Cale-se Cale-se sen""\xC6""o me deixa louco com seu papo furado!!";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Os caras que criaram esse jogo s""\xC6""o os melhores!!";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Sem eles a Knuf Kcuf n""\xC6""o funciona...Agora vai logo para o po""\x87""o!!";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Taaaa taaa....Tudo eu";
     goto poscheat;
     }
     if(nome[0]=='L'&&nome[1]=='i'&&nome[2]=='n'&&nome[3]=='u'&&nome[4]=='s')
     {
     gotoxy(2,g);g++;
     cout<<"Soldado :Nossaa!! Linus, O senhor PotHix aqui por essas bandas";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Nem posso acreditar!! O que tem feito desde que construiu";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :essa maravilhosa hist""\xA2""ria onde eu sou um coadjuvante?";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Bem cara...Eu estou apenas desfrutando do sucesso..heheh";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Nossa!! Que legal...Est""\xA0"" vindo testar o jogo novamente?";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :N""\xC6""o...Dessa vez eu estou s""\xA2"" jogando para se divertir mesmo...";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Aaaaaa...Como voc""\x88"" ja sabe o po""\x87""o fica logo ali a frente";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Claro que sim...Finalmente terminei...Por que tiveram";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :elementos do grupo que n""\xC6""o ajudaram em nada...";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Eu imagino!! Sempre tem esse tipo de pessoa...";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :E ainda acham que est""\xC6""o fazendo bastante coisa ainda...hehheh";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado: Ainda bem que voc""\x88"" est""\xA0"" por ae para poder fazer a coisa andar";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :hehe...Obrigado...Agora vou indo...H""\xA0"" bra""\x87""os";
     goto poscheat;
     }
     g++;gotoxy(2,g);g++;
     cout<<"Soldado :Bom dia Sr. "<<nome<<".";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Vejo que voce chegou a pouco de fora.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Posso perguntar o que faz por aqui?";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Procuro o po""\x87""o dos desejos";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Mais um ca""\x87""ador de tesouro ... tenha cuidado.";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Com certeza terei";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Voc""\x88"" sabe onde fica esse po""\x87""o?";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Fica a frente perto da floresta.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Soldado :Mas eu repito, Cuidado com aquele po""\x87""o, n""\xC6""o \x82 t""\xC6""o simples";
     gotoxy(2,g);g++;delay(250);
     cout<<"quanto parece.";
     gotoxy(2,g);g++;delay(250);
     cout<<nome<<" :Eu irei e conseguirei retornar com o tesouro.";
     poscheat:{}
     gotoxy(2,22);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     //Cria""\x87""""\xC6""o de personagem
     clrscr();
     menun();
     g=2;
     gotoxy(20,g);g++;
     cout<<" ***DIA DE HEROI*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"CRIACAO DE PERSONAGEM:";
     hability=dados1();hability=hability+6;
     g++;
     gotoxy(2,g);g++;delay(250);
     cout<<"Sua habilidade e "<<hability;
     energy=dados2();energy=energy+12;
     gotoxy(2,g);g++;delay(250);
     cout<<"Sua energia e "<<energy;
     luck=dados1();luck=luck+6;
     gotoxy(2,g);g++;delay(250);
     cout<<"Sua sorte e "<<luck;
     g++;
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" possui uma espada, a sua mochila, uma lamparina ";
     gotoxy(2,g);g++;delay(250);
     cout<<"e 2 provis""\xE4""es";
     delay(1000);
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     //fim da cria""\x87""""\xC6""o de personagem
     clrscr();
     menun();
     g=2;
     gotoxy(20,g);g++;delay(250);
     cout<<" ***O POCO DOS DESEJOS*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" chega ao po""\x87""o que procurava.";
     gotoxy(2,g);g++;delay(250);
     cout<<"""\x90"" um po""\x87""o de pedra e tem duas roldanas presas a um pequeno tronco de madeira";
     gotoxy(2,g);g++;delay(250);
     cout<<"onde, fica enrolada uma corda com um balde cinzento, aparentemente de ferro.";
     g++;
     gotoxy(2,g);g++;delay(250);
     a:
     {}
     cout<<"O que deseja fazer?(selecione um numero)";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Jogar uma pedra e ver o que acontece.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Deixar o balde descer at""\x82"" o fundo.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Amarrar a corda por sobre o po""\x87""o e descer.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
	     case 1:
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Voc""\x88"" jogou a pedra a percebe que ele bate em algo um tanto quanto";
		      gotoxy(2,g);g++;delay(250);
	          cout<<"s""\xA2""lido, e percebe que n""\xC6""o h""\xA0"" aparentemente nada de anormal no fundo";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"apenas um fundo seco.";
	          gotoxy(2,22);g++;delay(250);
	          cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              break;
	     case 2:
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Voc""\x88"" deixou o balde descer at""\x82"" o fundo do po""\x87""o e ele se chocou com um";
	          gotoxy(2,g);g++;delay(250);
              cout<<"fundo aparentemente s""\xA2""lido.";
	          delay(1000);
	          gotoxy(2,22);g++;delay(250);
	          cout<<"Aperte qualquer tecla para continuar";
	          go=getch();
	          break;
	     case 3:
	          gotoxy(2,g);g++;delay(250);
		      cout<<"Voc""\x88"" amarrou a corda e desceu at""\x82"" o fundo, e para sua sorte o solo";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"estava livre de maiores obst""\xA0""culos.";
	          delay(1000);
	          break;
	     default:
              gotoxy(2,18);g++;delay(250);
	          cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	          delay(1000);
	          gotoxy(2,22);g++;delay(250);
	          cout<<"Aperte qualquer tecla para continuar";
	          go=getch();
              clrscr();
              menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***O POCO DOS DESEJOS*** ";
	      gotoxy(2,g);g++;delay(250);
	          goto a;
     }
     if(op==1||op==2)
     {
         clrscr();
         menun();
         g=2;
         gotoxy(20,g);g++;delay(250);
         cout<<" ***O POCO DOS DESEJOS*** ";
	     gotoxy(2,g);g++;delay(250);
	     cout<<"Voc""\x88"" percebeu que h""\xA0"" um fundo aparentemente seguro para descer.";
	     gotoxy(2,g);g++;delay(250);
	     cout<<"Voc""\x88"" deseja descer? (S ou N)";
         g++;
         gotoxy(2,g);g++;delay(250);
	     cout<<"OBS: Se voc""\x88"" n""\xC6""o descer estar""\xA0"" desistindo da aventura";
	     go=getch();
      if(go=='n'||go=='N')
	     {
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" desiste de uma aventura que pode ser s""\xA2"" para pessoas realmente";
              gotoxy(2,g);g++;delay(250);
	          cout<<"corajosas e volta para casa pensando em algum dia tomar coragem o ";
              gotoxy(2,g);g++;delay(250);
              cout<<"suficiente para enfrentar o desconhecido. E come""\x87""a a construir ";
              gotoxy(2,g);g++;delay(250);
              cout<<"uma vida sem saber que mist""\x82""rios podem estar esperando...";
              gotoxy(2,22);g++;delay(250);
     	      cout<<"Aperte qualquer tecla para continuar";
     	      go=getch();
              goto end;
         }
     }
     delay(1000);
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr();
     menun();
     g=2;
     aposent1=1;
     gotoxy(20,g);g++;delay(250);
     cout<<" ***O POCO DOS DESEJOS*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" est""\xA0"" no fundo do po""\x87""o seco. As paredes est""\xC6""o emplastadas de lama";
     gotoxy(2,g);g++;delay(250);
     cout<<"seca e o ch""\xC6""o sob seus p""\x82""s ""\x82"" lamacento.H""\xA0"" uma estreita passagem";
     gotoxy(2,g);g++;delay(250);
     cout<<"indo para o norte. Voc""\x88"" tem a vis""\xC6""o de apenas 1 metro a sua frente";
     gotoxy(2,g);g++;delay(250);
     cout<<"est""\xA0"" muito escuro...";
     g++;gotoxy(2,g);g++;delay(250);
     b:{}
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Caminhar normalmente ate o fim do t""\xA3""nel para examinar seu final.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Caminhar com cautela tateando as paredes.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Acender a lamparina e caminhar t""\xA3""nel a dentro.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" come""\x87""ou a caminhar normalmente ignorando o escuro, quando";
              gotoxy(2,g);g++;delay(250);
              cout<<"de repente voc""\x88"" trope""\x87""a numa pedra que ali esta, cai e perde";
              gotoxy(2,g);g++;delay(250);
              cout<<"1 ponto de energia.";
              energy--;
              g++;gotoxy(2,g);g++;delay(250);
              cout<<"Deseja acender a lamparina?(S ou N)";
              go=getch();
           if(go=='n'||go=='N')
              {
                   clrscr();menun();g=2;
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" escorrega novamente e bate a cabeca em uma pedra pontuda";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"e desmaia. Voc""\x88"" comeca a sentir mordidas e arranhões";
		           gotoxy(2,g);g++;delay(250);
                   cout<<"Quando acorda voc""\x88"" esta amarrado a um circulo de madeira";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"na diagonal, sem roupas e com ratos sobre seu corpo.";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"E assim voce morre gritando e agonizando com ratos comendo";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"voc""\x88"" para largar de ser burro e acender a droga da lamparina!!";
                   gotoxy(2,22);g++;delay(250);
     	           cout<<"Aperte qualquer tecla para continuar";
     	           go=getch();
                   goto dead;
              }
              break;
         case 2:
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" come""\x87""ou a caminhar tateando as paredes lamacentas, ";
              gotoxy(2,g);g++;delay(250);
              cout<<"mas percebeu que est""\xA0"" bem escuro.";
              g++;gotoxy(2,g);g++;delay(250);
	          cout<<"Deseja acender a lamparina?(S ou N)";
              go=getch();
           if(go=='n'||go=='N')
              {
                   clrscr();menun();g=2;
                   gotoxy(20,g);g++;delay(250);
                   cout<<" ***O POCO DOS DESEJOS*** ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" continua tateando as paredes e andando lentamente ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"pelo t""\xA3""nel, voc""\x88"" sente um pouco de lama lhe grudando ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"nas m""\xC6""os, mas continua no mesmo ritmo. No meio do ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"caminho voc""\x88"" sente algo que parece uma pedra.";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" deseja acender a lamparina para averiguar? (S ou N)";
                   go=getch();
                   if(go=='s'||go=='S')
                   {
                        g++;
                        gotoxy(2,g);g++;delay(250);
                        cout<<"""\x90"" somente uma pedra e voc""\x88"" se assustou a toa";
		   }
                   else
                   {
                        g++;
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" continua seguindo o seu caminho tateando as paredes.";
                   }
                   delay(1000);
                   gotoxy(2,22);g++;delay(250);
                   cout<<"Aperte qualquer tecla para continuar";
                   go=getch();
                   break;
              }
         case 3:
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" acende a lamparina e percebe que n""\xC6""o h""\xA0"" nada alem de algumas";
              gotoxy(2,g);g++;delay(250);
              cout<<"simples pedras no caminho, voc""\x88"" ent""\xC6""o desvia desse obst""\xA0""culo";
              gotoxy(2,g);g++;delay(250);
              cout<<"e segue o caminho.";
              delay(1000);
	      gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              break;
         default:
              gotoxy(2,18);g++;delay(250);
              cout<<"N""\xC6""o existe essa opc""\xC6""o";
              delay(1000);
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr();
              menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***O POCO DOS DESEJOS*** ";
              gotoxy(2,g);g++;delay(250);
              goto b;
     }
     clrscr();
     menun();
     g=2;
     aposent2=1;
     gotoxy(20,g);g++;delay(250);
     cout<<" ***APOSENTO 2*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"A passagem continua em dire""\x87""""\xC6""o norte por mais 20 metros e ent""\xC6""o ";
     gotoxy(2,g);g++;delay(250);
     cout<<"acaba em uma s""\xA2""lida porta. As paredes da passagem s""\xC6""o rochosas e o";
     gotoxy(2,g);g++;delay(250);
     cout<<" ch""\xC6""o ""\x82"" lamacento.A passagem finda em uma porta s""\xA2""lida em forma de ";
     gotoxy(2,g);g++;delay(250);
     cout<<"arco, com uma pequena ma""\x87""aneta enferrujada, voc""\x88"" tenta girar a ";
     gotoxy(2,g);g++;delay(250);
     cout<<"ma""\x87""aneta e percebe que ele n""\xC6""o se mexe, pois a porta est""\xA0"" trancada.";
     g++;
     gotoxy(2,g);g++;delay(250);
     c:{}
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Colocar o ouvido na porta para tentar escutar alguma coisa";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Bater na porta para ver o que acontece";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Tentar derrubar a porta na for""\x87""a bruta.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Voc""\x88"" enconsta o ouvido na porta e ouve um barulho fraco parecido";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"com ratos, asas batendo, voc""\x88"" n""\xC6""o sabe distinguir ao certo.";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr();
              menun();
              g=2;
	          gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 2*** ";
              gotoxy(2,g);g++;delay(250);
              bporta:{}
              cout<<"O que deseja fazer?";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"1. Bater na porta para ver o que acontece";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"2. Derrubar a porta na for""\x87""a bruta.";
	          g++;gotoxy(2,g);delay(250);
	          cin>>go;
		      if(go=='1')
	          {
		           goto op1;
              }
	          else
	          {
		           goto op2;
              }
        case 2:
	          op1:{}
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Voc""\x88"" bate na porta e escuta uma voz grave que vem de dentro do ";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"aposento dizendo:";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"- Cuidado, visitantes indesejados!! Quaisquer ";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"pessoas que aqui entrem encaram a morte certa!. ";
	          g++;
	          delay(1000);
	          gotoxy(2,22);g++;delay(250);
	          cout<<"Aperte qualquer tecla para continuar";
	          go=getch();
              clrscr();
              menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
	      cout<<" ***APOSENTO 2*** ";
              gotoxy(2,g);g++;delay(250);
              goto bporta;
	     case 3:
	          op2:{}
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Voc""\x88"" se lan""\x87""a contra a porta e ela emite um som rouco";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"e voc""\x88"" ouve uma voz:";
	          gotoxy(2,g);g++;delay(250);
              cout<<"- Cuidado, visitantes indesejados!! Quaisquer pessoas que";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"aqui entrem encaram a morte certa!”. ";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Deseja tentar novamente?(S ou N)";
	          go=getch();
           if(go=='s'||go=='S')
	          {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" se lan""\x87""a contra a porta ela se abre bruscamente";
		   gotoxy(2,g);g++;delay(250);
                   cout<<"revelando o que se encontra dentro do aposento.";
              }
              else
              {
                   gotoxy(2,22);g++;delay(250);
                   cout<<"Aperte qualquer tecla para continuar";
                   go=getch();
                   clrscr();
                   menun();
                   g=2;
                   gotoxy(20,g);g++;delay(250);
                   cout<<" ***APOSENTO 2*** ";
                   gotoxy(2,g);g++;delay(250);
                   goto c;
              }
              delay(1000);
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              break;
         default:
              gotoxy(2,18);g++;delay(250);
              cout<<"N""\xC6""o existe essa opcao";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr();
	          menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 2*** ";
              gotoxy(2,g);g++;delay(250);
              goto c;
     }
     aposento3:{}
     clrscr();
     menun();
     g=2;
     aposent3=1;
     gotoxy(20,g);g++;delay(250);
     cout<<"***APOSENTO 3***";
     gotoxy(2,g);g++;delay(250);
     cout<<" O aposento ""\x82"" retangular e h""\xA0"" portas fechadas no meio de cada uma  ";
     gotoxy(2,g);g++;delay(250);
     cout<<"das paredes que v""\xC6""o para o Norte, sul e leste. P""\xA0""ssaros batem  ";
     gotoxy(2,g);g++;delay(250);
     cout<<"as asas pelo aposento, mas, quando voc""\x88"" entra, todos voam para um ";
     gotoxy(2,g);g++;delay(250);
     cout<<"canto se aninham na barba de um homem que est""\xA0"" sentado frente a uma ";
     gotoxy(2,g);g++;delay(250);
     cout<<"mesa.Ele ""\x82"" baixo e compacto, e sua longa barba cai sobre a mesa. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Ele est""\xA0"" pegando pequenos objetos redondos de dentro de uma bolsa e ";
     gotoxy(2,g);g++;delay(250);
     cout<<"jogando-os na boca.deve ser algum tipo de noz. Quando voc""\x88"" entra ele ";
     gotoxy(2,g);g++;delay(250);
     cout<<"levanta uma sombracelha.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Thrushbeard: Hey, meu nome ""\x82"" Thrushbeard, e quem ""\x82"" voc""\x88""? O que ";
     gotoxy(2,g);g++;delay(250);
     cout<<"procura aqui?(escolha uma das respostas)";
     f:{}
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Meu nome ""\x82"" "<<nome<<" .Fiquei sabendo que aqui neste po""\x87""o h""\xA0"" ";
     gotoxy(2,g);g++;delay(250);
     cout<<"escondido um tesouro, isso ""\x82"" verdade?";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Meu nome ""\x82"" " <<nome<<" ,e procuro por algo de valor por aqui, voc""\x88"" ";
     gotoxy(2,g);g++;delay(250);
     cout<<"pode me ajudar?";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
	     case 1:
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Trushbeard: Haha...Voc""\x88"" est""\xA0"" atras do tesouro? Realmente ""\x82"" verdade";
	          gotoxy(2,g);g++;delay(250);
	          cout<<", mas voc""\x88"" nunca conseguir""\xA0"" pegar o tesouro se voc""\x88"" n""\xC6""o  ";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"tiver a chave de cristal para entrar na sala do Rei";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              ot:{}
	          clrscr();
              menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 3*** ";
              gotoxy(2,g);g++;delay(250);
	          cout<<"1. Voc""\x88"" tem a chave?";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"2. Onde posso encontrar a tal chave de cristal?";
	          gotoxy(2,g);g++;delay(250);
	          cout<<"3. Voc""\x88"" pode me ajudar a pegar o tesouro?";
              g++;gotoxy(2,g);delay(250);
	          cin>>op;
		      switch(op)
	          {
                   case 1:
                        gotoxy(2,g);g++;delay(250);
                        cout<<"N""\xC6""o eu n""\xC6""o tenho a chave";
                        gotoxy(2,22);g++;delay(250);
	                    cout<<"Aperte qualquer tecla para continuar";
                        go=getch();
			            goto ot;
                   case 2:
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Te diria se soubesse...";
                        gotoxy(2,22);g++;delay(250);
	                    cout<<"Aperte qualquer tecla para continuar";
                        go=getch();
                        goto ot;
                   case 3:
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Trushbeard: N""\xC6""o...N""\xC6""o posso te ajudar, n""\xC6""o sei mais a respeito";
                        gotoxy(2,22);g++;delay(250);
	                    cout<<"Aperte qualquer tecla para continuar";
                        go=getch();
                        goto nzt;
              }
              case 2:
                        gotoxy(2,g);g++;delay(250);
	                    cout<<"Trushbeard: Talvez voc""\x88"" encontre algo de valor aqui em baixo,  ";
			            gotoxy(2,g);g++;delay(250);
	                    cout<<"mas n""\xC6""o pense que ser""\xA0"" f""\xA0""cil";
                        break;
              default:
                        gotoxy(2,18);g++;delay(250);
	                    cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	                    delay(1000);
	                    gotoxy(2,22);g++;delay(250);
	                    cout<<"Aperte qualquer tecla para continuar";
	                    go=getch();
                        clrscr();
                        menun();
                        g=2;
                        gotoxy(20,g);g++;delay(250);
                        cout<<" ***APOSENTO 3*** ";
                        goto f;
     }
     // Noz time
     delay(1000);
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     nzt:{}
     clrscr();
     menun();
     g=2;
     aposent3=1;
     gotoxy(20,g);g++;delay(250);
     cout<<" ***APOSENTO 3*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Thrushbeard lhe joga uma Noz.";
	 noztime:{}
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Eu vou come-la.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. N""\xC6""o vou come-la.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Eu pergunto a ele sobre as nozes enquanto vejo se ele come mais ";
     gotoxy(2,g);g++;delay(250);
     cout<<"alguma do mesmo lugar que tirou a que me deu.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
              noz:{}
              if(dados2()<luck)
              {
                   energy++;
                   luck--;
                   gotoxy(2,g);g++;delay(250);
                   cout<<"A noz que ele te deu est""\xA0"" boa. Voc""\x88"" ganha 1 ponto de energia";
              }
              else
              {
                   energy--;
                   luck--;
                   gotoxy(2,g);g++;delay(250);
		           cout<<"A noz que ele te deu est""\xA0"" estragada.Voc""\x88"" perde 1 ponto de energia";
              }
              break;
         case 2:
              noz2:{}
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" nota claramente que Trushbeard fica chateado.";
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" ir""\xA0"" comer? (S ou N)";
              go=getch();
              if(go=='s'||go=='S')
              {
                   goto noz;
              }
              break;
         case 3:
              gotoxy(2,g);g++;delay(250);
              cout<<"Thrushbeard diz: As nozes eu recebo de um amigo que as jogou ";
              gotoxy(2,g);g++;delay(250);
              cout<<"po""\x87""o abaixo...Elas s""\xC6""o muito boas, eu as como com frequ""\x88""ncia ";
	          gotoxy(2,g);g++;delay(250);
              cout<<"( enquanto isso ele retira mais uma da mesma bolsa a qual ele ";
              gotoxy(2,g);g++;delay(250);
              cout<<"tirou a que te deu e come ).";
              gotoxy(2,g);g++;delay(250);
              cout<<"O que deseja fazer?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Eu vou comer a Noz que ele me deu.";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. Mesmo vendo ele comendo uma, prefiro n""\xC6""o arriscar.";
              gotoxy(2,g);g++;delay(250);
              go=getch();
              if(go=='2')
              {
                    goto noz2;
              }
              else
              {
                   goto noz;
              }

         default:
              gotoxy(2,18);g++;delay(250);
	          cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	          delay(1000);
	          gotoxy(2,22);g++;delay(250);
	          cout<<"Aperte qualquer tecla para continuar";
		      go=getch();
              clrscr();
              menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 3*** ";
              goto noztime;
     }
     if(op==1)
     {
         gotoxy(2,g);g++;delay(250);
         cout<<"ThrushBeard diz:";
         gotoxy(2,g);g++;delay(250);
         cout<<"Bem, como pode ver, h""\xA0"" tr""\x88""s portas nessa sala, cada uma leva a ";
         gotoxy(2,g);g++;delay(250);
         cout<<"um local diferente, siga seu caminho e tente encontrar o que ";
	     gotoxy(2,g);g++;delay(250);
         cout<<"estava procurando. Todas essas tr""\x88""s portas est""\xC6""o destrancadas, ";
         gotoxy(2,g);g++;delay(250);
         cout<<"sinta-se a vontade.";
     }
     else
     {
         gotoxy(2,g);g++;delay(250);
         cout<<"Como dito anteriormente h""\xA0"" 4 portas na sala, sendo que a porta sul";
         gotoxy(2,g);g++;delay(250);
         cout<<"""\x82"" a mesma que voc""\x88"" utilizou para chegar a essa sala. Todas as ";
         gotoxy(2,g);g++;delay(250);
         cout<<"portas da sala est""\xC6""o destrancadas.";
     }
     delay(1000);
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr();
     menun();
     apos3ao:{}
     g=2;
     gotoxy(20,g);g++;delay(250);
     cout<<" ***APOSENTO 3*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Qual porta deseja seguir?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Leste";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Norte";
     gotoxy(2,g);g++;delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
              gotoxy(2,18);g++;delay(250);
              cout<<"Voc""\x88"" seguiu pela porta leste";
              delay(1000);
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              goto aposento4;
         case 2:
              gotoxy(2,18);g++;delay(250);
              cout<<"Voc""\x88"" seguiu pela porta norte";
              delay(1000);
              go=getch();
	          goto aposento8;
         default:
              gotoxy(2,18);g++;delay(250);
	          cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	          delay(1000);
	          gotoxy(2,22);g++;delay(250);
	          cout<<"Aperte qualquer tecla para continuar";
	          go=getch();
              clrscr();
              menun();
              goto apos3ao;
     }
     //fim do aposento 3///////////////////////////////////////////////////////
     //Aposento 4//////////////////////////////////////////////////////////////
     aposento4:{}
     aposent4=1;
     clrscr();
     menun();
     g=2;
     aposent4=1;
     gotoxy(20,g);g++;delay(250);
     cout<<"***APOSENTO 4***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Neste aposento h""\xA0"" portas que levam para o norte,sul e leste. O ch""\xC6""o ";
     gotoxy(2,g);g++;delay(250);
     cout<<"nu ""\x82"" rochoso,e voc""\x88"" n""\xC6""o podem ver nada vivo l""\xA0"" dentro.Ao longo da ";
     gotoxy(2,g);g++;delay(250);
     cout<<"parede h""\xA0"" um grande retrato de um guerreiro vestindo uma armadura de ";
     gotoxy(2,g);g++;delay(250);
     cout<<"batalha. Uma grande tabuleta sobre o retrato diz:";
     gotoxy(2,g);g++;delay(250);
     cout<<"Estes objetos s""\xC6""o de propriedade de Marg, O mestre dos assassinos.";
     gotoxy(2,g);g++;delay(250);
     cout<<"N""\xC6""o os toque, se sua vida voc""\x88"" valoriza.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Os objetos referidos na mensagem s""\xC6""o:";
     gotoxy(2,g);g++;delay(250);
     cout<<"- Um colar de prata";
     gotoxy(2,g);g++;delay(250);
     cout<<"- Uma pequena bolsa de couro";
     gotoxy(2,g);g++;delay(250);
     cout<<"- Um machado";
     gotoxy(2,g);g++;delay(250);
     cout<<"- Uma brilhante j""\xA2""ia presa a um pingente";
     gotoxy(2,g);g++;delay(250);
     cout<<"O aposento ""\x82""  iluminado por uma tocha que est""\xA0"" presa em uma rachadura ";
     gotoxy(2,g);g++;delay(250);
     cout<<"da parede.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Enquanto voc""\x88"" caminha pelo quarto examinando o local, voc""\x88"" percebe ";
     gotoxy(2,g);g++;delay(250);
     cout<<"que os olhos do retrato que est""\xA0"" na parede o perseguem.";
     delay(1000);
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr();
     menun();
     g=2;
     gotoxy(20,g);g++;delay(250);
     cout<<"***APOSENTO 4***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" deseja pegar algum item? (S ou N)";
     go=getch();
     if(go=='n'||go=='N')
     {
         goto positens;
     }
     gotoxy(2,g);g++;delay(250);
     cout<<"Quando voc""\x88"" chega perto de algum objeto voc""\x88"" ouve um profundo ";
     gotoxy(2,g);g++;delay(250);
     cout<<"ribombar, que s""\xA2"" para quando voc""\x88"" se afasta do objeto.";
     g++;
     gotoxy(2,g);g++;delay(250);
     cout<<"Ainda deseja pegar algum item?(S ou N)";
     go=getch();
     if(go=='n'||go=='N')
     {
         goto positens;
     }
     gotoxy(2,g);g++;delay(250);
     cout<<"Deseja pegar o machado? (S ou N)";
     go=getch();
     if(go=='s'||go=='S')
     {
         gotoxy(2,g);g++;delay(250);
         cout<<"Quando voc""\x88"" tira o item de seu local voc""\x88"" ouve passos vindos de ";
         gotoxy(2,g);g++;delay(250);
         cout<<"todos os lados, voc""\x88"" olha para as portas e elas n""\xC6""o se mexem, e ";
         gotoxy(2,g);g++;delay(250);
         cout<<"os passos v""\xC6""o ficando cada vez mais altos, quando de repente, ";
         gotoxy(2,g);g++;delay(250);
         cout<<"eles se dissipam, e o sil""\x88""ncio toma conta novamente da sala.";
         axe=1;
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" colocou o machado na sua mochila.";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
	     clrscr();
         menun();
         g=2;
         gotoxy(20,g);g++;delay(250);
         cout<<"***APOSENTO 4***";
     }
     gotoxy(2,g);g++;delay(250);
     cout<<"Deseja pegar o colar? (S ou N)";
     go=getch();
     if(go=='s'||go=='S')
     {
         gotoxy(2,g);g++;delay(250);
         cout<<"Quando voc""\x88"" tira o item de seu local voc""\x88"" ouve passos vindos de ";
         gotoxy(2,g);g++;delay(250);
         cout<<"todos os lados, voc""\x88"" olha para as portas e elas n""\xC6""o se mexem, e ";
         gotoxy(2,g);g++;delay(250);
         cout<<"os passos v""\xC6""o ficando cada vez mais altos, quando de repente, ";
         gotoxy(2,g);g++;delay(250);
         cout<<"eles se dissipam, e o silencio toma conta novamente da sala.";
         colar=1;
         gotoxy(2,g);g++;delay(250);
         cout<<"Deseja usar o colar? (S ou N)";
         go=getch();
         if(go=='s'||go=='S')
         {
              if(dados2()<hability)
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" colocou o colar no pesco""\x87""o e come""\x87""ou a sentir";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"ele prendendo sua respira""\x87""""\xC6""o... ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Felizmente voc""\x88"" conseguiu tirar mas foi muito dificil";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"por isso voc""\x88"" perdeu 1 ponto de Energia";
                   energy--;
              }
              else
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" colocou o colar e sentiu ele te sufocando rapidamente ";
                   gotoxy(2,g);g++;delay(250);
		           cout<<"e voc""\x88"" n""\xC6""o consegue mais respirar de maneira nenhuma, ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"voc""\x88"" cai no ch""\xC6""o e continua tentando tirar o colar, voc""\x88"" ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"tenta pedir ajuda mas n""\xC6""o consegue, at""\x82"" que tudo come""\x87""a a ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"ficar escuro e voc""\x88"" morre naquela sala, olhando a tabuleta ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"do retrato que dizia: “Estes objetos pertencem a Marg o ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"mestre dos assassinos. N""\xC6""o o toque se sua vida voc""\x88"" valoriza.”, ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"voc""\x88"" tamb""\x82""m lembra das palavras de Thrushbeard: “Quaisquer ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"pessoas que entrarem aqui enfrentam a morte certa”. No seu ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"ultimo olhar voc""\x88"" viu o retrato de Marg te olhando com um ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"leve sorriso em sua face.";
                   gotoxy(2,22);g++;delay(250);
                   cout<<"Aperte qualquer tecla para continuar";
                   go=getch();
                   goto dead;
	      }
         }
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" colocou o colar na sua mochila.";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr();
         menun();
         g=2;
         gotoxy(20,g);g++;delay(250);
         cout<<"***APOSENTO 4***";
     }
     gotoxy(2,g);g++;delay(250);
     cout<<"Deseja pegar o pingente? (S ou N)";
     go=getch();
     if(go=='s'||go=='S')
     {
         gotoxy(2,g);g++;delay(250);
         cout<<"Quando voc""\x88"" coloca sua m""\xC6""o sobre o pingente voc""\x88"" o v""\x88"" ";
         gotoxy(2,g);g++;delay(250);
         cout<<"se transformando em agua e escapando pelos seus dedos deixando";
	     gotoxy(2,g);g++;delay(250);
         cout<<"apenas a base de metal";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr();
         menun();
         g=2;
         gotoxy(20,g);g++;delay(250);
         cout<<"***APOSENTO 4***";
     }
     gotoxy(2,g);g++;delay(250);
     cout<<"Deseja pegar a bolsa (S ou N)";
     go=getch();
     if(go=='s'||go=='S')
     {
         gotoxy(2,g);g++;delay(250);
         cout<<"Quando voc""\x88"" pega a bolsa voc""\x88"" sente que existe algo dentro dela";
         gotoxy(2,g);g++;delay(250);
         cout<<"ap""\xA2""s verificar voc""\x88"" nota que h""\xA0"" uma moeda de ouro dentro ";
         gotoxy(2,g);g++;delay(250);
         cout<<"ent""\xC6""o voc""\x88"" guarda a moeda dentro da sua mochila junto da bolsinha";
	     gotoxy(2,g);g++;delay(250);
         cout<<"de couro que l""\xA0"" estava.";
         ouro++;
     }
     g++;
     positens:{}
     gotoxy(2,g);g++;delay(250);
     cout<<"Qual porta deseja seguir?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Oeste";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Leste";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Norte";
     gotoxy(2,g);g++;delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
              gotoxy(2,18);g++;delay(250);
              cout<<"Voc""\x88"" seguiu pela porta oeste";
              if(aposent3==1)
              {
                   goto apos3b;
              }
              goto aposento3;
         case 2:
              gotoxy(2,18);g++;delay(250);
              cout<<"Voc""\x88"" seguiu pela porta leste";
              if(aposent5==1)
              {
                   goto apos5b;
              }
              goto aposento5;
         case 3:
              gotoxy(2,18);g++;delay(250);
              cout<<"Voc""\x88"" seguiu pela porta norte";
              if(aposent6==1)
              {
                   goto apos6b;
			  }
              goto aposento6;
         default:
              gotoxy(2,18);g++;delay(250);
	          cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	          delay(1000);
	          gotoxy(2,22);g++;delay(250);
	          cout<<"Aperte qualquer tecla para continuar";
	          go=getch();
              clrscr();
              menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<"***APOSENTO 4***";
              goto positens;
     }
     //fim do aposento 4///////////////////////////////////////////////////////
     //APOSENTO 5//////////////////////////////////////////////////////////////
     aposento5:{}
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr();
     menun();
     g=2;
     aposent5=1;
     gotoxy(20,2);g++;delay(250);
     cout<<" ***APOSENTO 5*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"As paredes desse aposento est""\xC6""o nuas, com v""\xA0""rias rachaduras n""\xC6""o ";
     gotoxy(2,g);g++;delay(250);
     cout<<"somente nas paredes mas tambem no ch""\xC6""o, com teias de aranha no canto ";
     gotoxy(2,g);g++;delay(250);
     cout<<"superior sem mais objetos relevantes. Voc""\x88"" entrou pela ""\xA3""nica porta.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Ele ""\x82"" um quadrado imperfeito, com paredes e ch""\xC6""o de pedra. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Um tanto quanto estranho um quarto desses.";
     g++;
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Examinar as rachaduras nas paredes e no ch""\xC6""o para ver se ";
     gotoxy(2,g);g++;delay(250);
     cout<<"encontra algum objeto que possa ser ""\xA3""til.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Examinar as paredes para saber se h""\xA0"" alguma passagem escondida.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Sair da sala.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     gotoxy(2,g);g++;delay(250);
     cout<<"Quando havia decidido o que faria e ia come""\x87""ar a se mover, uma";
     gotoxy(2,g);g++;delay(250);
     cout<<"coisa acontece...";
     gotoxy(2,22);g++;delay(250);
	 cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr();
     menun();
     g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<" ***APOSENTO 5*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Contornos est""\xC6""o come""\x87""ando a se formar no aposento. Voc""\x88"" pode";
     gotoxy(2,g);g++;delay(250);
     cout<<"perceber uma estante antiga cheia de Livros se materializando";
     gotoxy(2,g);g++;delay(250);
     cout<<"na parede norte. Uma lareira com um fogo crepitando est""\xA0"" se";
     gotoxy(2,g);g++;delay(250);
     cout<<"tornando vis""\xA1""vel no centro da parede leste. Um homem alto, magro";
     gotoxy(2,g);g++;delay(250);
     cout<<", est""\xA0"" de p""\x82"" ao lado da lareira, olhando para voc""\x88"". Ao longo da ";
     gotoxy(2,g);g++;delay(250);
     cout<<"parede sul h""\xA0"" um pedestal e, no topo dele, uma cuba com um ";
     gotoxy(2,g);g++;delay(250);
     cout<<"l""\xA1""quido fumegante.";
     g++;
     gotoxy(2,g);g++;delay(250);
     cout<<"O homem abre a boca e fala:";
     gotoxy(2,g);g++;delay(250);
     cout<<"- Ora! Nandras tem um visitante, n""\xC6""o ""\x82""? E o que este ";
     gotoxy(2,g);g++;delay(250);
     cout<<"invasor deseja aqui?";
     apos5a:{}
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr();
     menun();
     g=2;
     gotoxy(20,g);g++;delay(250);
     cout<<" ***APOSENTO 5*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Responder:Eu sou "<<nome<<" e estou aqui a procura de um tesouro";
     gotoxy(2,g);g++;delay(250);
     cout<<"que supostamente ficaria aqui guardado. Voc""\x88"" pode me dizer algo ";
     gotoxy(2,g);g++;delay(250);
     cout<<"a respeito?";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Responder:Eu sou "<<nome<<" e procuro algo que possa valer ";
     gotoxy(2,g);g++;delay(250);
     cout<<"o meu sacrif""\xA1""cio entrando nesse buraco. Voc""\x88"" sabe se eu vou ";
     gotoxy(2,g);g++;delay(250);
     cout<<"encontrar algo assim aqui ou ""\x82"" apenas uma perda de tempo?";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Responder: Eu me chamo "<<nome<<" e estou aqui por curiosidade,";
     gotoxy(2,g);g++;delay(250);
     cout<<"s""\xA2"" estou conhecendo os aposentos.";
     gotoxy(2,g);g++;delay(250);
     cout<<"4. Atacar Nandras sem lhe dizer uma palavra.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
          gotoxy(2,g);g++;delay(250);
          cout<<"E Nandras lhe responde:";
	      gotoxy(2,g);g++;delay(250);
          cout<<"Nandras: Ol""\xA0"" Sr. "<<nome<<" realmente aqui h""\xA0"" sim um ";
          gotoxy(2,g);g++;delay(250);
          cout<<"tesouro guardado, e pelo que pude perceber voc""\x88"" sabe ";
          gotoxy(2,g);g++;delay(250);
          cout<<"bastante sobre isso.";
          gotoxy(2,22);
          cout<<"Aperte qualquer tecla para continuar";
          go=getch();
          clrscr() ;menun(); g=2;
          gotoxy(20,g);g++;delay(250);
          cout<<" ***APOSENTO 5*** ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<nome<<": Como voc""\x88"" sabe disso?";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras: Eu posso ler mentes, e vejo claramente com quem";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"voc""\x88"" conversou e o que voc""\x88"" sabe.";
	      gotoxy(2,g);g++;delay(250);
	      cout<<nome<<": Eu realmente sei algo.O ThrushBeard me falou";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"sobre a chave de Cristal, voc""\x88"" sabe algo a respeito?";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras: Sim, Eu tenho a chave de Cristal.";
	      gotoxy(2,g);g++;delay(250);
          cout<<nome<<": Voc""\x88"" pode me dar a chave de cristal?";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras: Eu poderia fazer uma troca justa onde sair""\xA1""amos ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"beneficiados. Interessado?";
	      gotoxy(2,g);g++;delay(250);
	      cout<<nome<<": O que voc""\x88"" quer pela chave de cristal?";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandra:Tem uma mumia em um dos aposentos que est""\xA0"" me ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"causando aborrecimentos, se voc""\x88"" acabasse com ela eu lhe ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"daria a chave.";
	      gotoxy(2,g);g++;delay(250);
	      cout<<nome<<": Ok eu derrotarei a mumia e voltarei.";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras: Cuidado que uma mumia ""\x82"" um ser imortal, quando";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"voc""\x88"" conseguir derrota-la ter""\xA0"" de queima-la, tome esta";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"po""\x87""""\xC6""o e despeje nela e ela queimara instantaneamente.";
	      gotoxy(2,22);
	      cout<<"Aperte qualquer tecla para continuar";
	      go=getch();
          clrscr() ;menun(); g=2;
	      break;
	 case 2:
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras: Tome cuidado com suas palavras Sr."<<nome;
	      gotoxy(2,g);g++;delay(250);
	      cout<<"voc""\x88"" est""\xA0"" falando com Nandras o grande feiticeiro, e se";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"continuar com essa insol""\x88""ncia te transformarei em cinzas";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"em poucos instantes.";
	      goto apos5a;
	 case 3:
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras com um tom de sarcasmo: Haha, Sr. "<<nome<<" eu";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"posso ler seus pensamentos e vi que n""\xC6""o foi nem um pouco";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"sincero em sua resposta, posso ver que n""\xC6""o ""\x82"" honesto com";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"as pessoas que conversa.";
	      goto apos5a;
	 case 4:
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Assim que voc""\x88"" ataca Nandras ele j""\xA0"" havia lido seus ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"pensamentos e antecipava seu ataque e lan""\x87""ou uma magica";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"e de congelamento sobre voc""\x88"" e disse:";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras: Como ousas tentar me atacar!? Voc""\x88"" est""\xA0"" diante de Nandras";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"o grande feiticeiro, agora voc""\x88"" ficar""\xA0"" ai congelado. ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Nandras te olha atentamente e diz com um ligeiro sorriso de ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"goza""\x87""""\xC6""o na face:";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"O feiti""\x87""o vai durar""\xA0"" at""\x82"" que voc""\x88"" esfrie e cabe""\x87""a, e";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"quem sabe voc""\x88"" me possa ser ""\xA3""til afinal.";
	      goto apos5a;
	 default:
	      gotoxy(2,18);g++;delay(250);
		  cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	      goto apos5a;
     }
     gotoxy(20,g);g++;delay(250);
     cout<<" ***APOSENTO 5*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Ent""\xC6""o est""\xA0"" feito o nosso trato, volte quando tiver cumprido a sua";
     gotoxy(2,g);g++;delay(250);
     cout<<"parte que cumprirei a minha.";
     g++;
     gotoxy(2,g);g++;delay(250);
     cout<<"Nandras desaparece juntamente com os objetos que com ele vieram.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Ent""\xC6""o vendo que n""\xC6""o havia mais nada para fazer ali voc""\x88"" se retira.";
     gotoxy(2,22);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     goto apos4b;
     //fim do aposento 5 //////////////////////////////////////////////////////
     //ODEIO FAZER DIALOGOS S""\xC6""O MUITO CANSATIVOS E CHEIOS DE POR""\x82""NS!!!!!!!!!!!!
     //APOSENTO 6 porta norte do Marg//////////////////////////////////////////
     aposento6:{}
     aposent6=1;
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 6***";
     gotoxy(2,g);g++;delay(250);
     cout<<"A porta que d""\xA0"" para este aposento ""\x82"" feita de pedras, mas est""\xA0"" ";
     gotoxy(2,g);g++;delay(250);
     cout<<"destrancada. Depois da porta h""\xA0"" um grande aposento. Sua lamparina ";
     gotoxy(2,g);g++;delay(250);
     cout<<"ilumina estranhos hier""\xA2""glifos ( escrita em desenhos ), que cobrem ";
     gotoxy(2,g);g++;delay(250);
     cout<<"as paredes. No centro do aposento, sobre um altar de pedra, h""\xA0"" um ";
     gotoxy(2,g);g++;delay(250);
     cout<<"grande sarc""\xA2""fago de pedra, parecendo ser bem velho. O sarc""\xA2""fago ";
     gotoxy(2,g);g++;delay(250);
     cout<<"est""\xA0"" aberto e sua tampa no formato eg""\xA1""pcio de grandes fara""\xA2""s ";
     gotoxy(2,g);g++;delay(250);
     cout<<"est""\xA0"" encostada no Altar.Quando voc""\x88"" entra na sala uma forma emerge";
     gotoxy(2,g);g++;delay(250);
     cout<<"do sarc""\xA2""fago, ""\x82"" uma forma humana aparentemente de uma pessoa ";
     gotoxy(2,g);g++;delay(250);
     cout<<"magra, mas quando voc""\x88"" aponta sua lamparina, percebe que est""\xA0"" ";
     gotoxy(2,g);g++;delay(250);
     cout<<"envolta por bandagens e caminha em sua dire""\x87""""\xC6""o, ent""\xC6""o voc""\x88"" percebe";
     gotoxy(2,g);g++;delay(250);
     cout<<"que acabou de atormentar uma mumia.";
     gotoxy(2,g);g++;delay(250);
     cout<<"A mumia vem em sua dire""\x87""""\xC6""o e est""\xA0"" prestes a atac""\xA0""-lo. O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Lutar com a Mumia";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Fugir";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     if(op==1)
     {
         mumyf:{}
         enemy=1;
	     energy=fight();
	     go=getch();
         clrscr() ;menun(); g=2;
	     if(energy<=0)
         {
	      goto dead;
         }
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 6***";
         gotoxy(2,g);g++;delay(250);
	     cout<<"Voc""\x88"" derruba a mumia em uma batalha digna de livros de est""\xA2""rias";
         gotoxy(2,g);g++;delay(250);
         cout<<"e joga a po""\x87""""\xC6""o que Nandras te deu sobre as bandagens";
         gotoxy(2,g);g++;delay(250);
         cout<<"elas expelem uma grossa camada de fuma""\x87""a e transformam-se em ";
         gotoxy(2,g);g++;delay(250);
         cout<<"cinzas... miss""\xC6""o completa voc""\x88"" pensa";
     }
     else
     {
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" tenta correr da mumia e ela o acerta no ombro enquanto";
         gotoxy(2,g);g++;delay(250);
         cout<<"voc""\x88"" fugia e voc""\x88"" n""\xC6""o ""\x82"" capaz de escapar ";
         gotoxy(2,g);g++;delay(250);
         cout<<"por isso perdeu dois pontos de energia. E ela lhe ataca";
         energy--;
         energy--;
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         goto mumyf;
     }
     g++;
     gotoxy(2,g);g++;delay(250);
     cout<<"Deseja revistar o aposento da mumia? (S ou N)";
     go=getch();
     if(go=='s'||go=='S')
     {
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" encontra 12 moedas de ouro e uma esmeralda (29 de ouro).";
     ouro=ouro+41;
     }
     gotoxy(2,g);g++;delay(250);
     cout<<"Tendo cumprido a sua parte no seu acordo voc""\x88"" abandona o aposento.";
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     goto apos4b;
     //fim do aposento 6//////////////////////////////////////////////////////
     //Aposento 8//////////////////////////////////////////////////////////////
     aposento8:{}
     aposent8=1;
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 8***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Este aposento se parece com algum tipo de pris""\xC6""o. As paredes ";
     gotoxy(2,g);g++;delay(250);
     cout<<"s""\xC6""o nuas, feitas de blocos de concreto, e est""\xC6""o bem sujas e ";
     gotoxy(2,g);g++;delay(250);
     cout<<"empoeiradas. O ch""\xC6""o tamb""\x82""m est""\xA0"" empoeirado e cheio de peda""\x87""os ";
     gotoxy(2,g);g++;delay(250);
     cout<<"de madeira e pedra. Alguns ossos est""\xC6""o espalhados pelo ch""\xC6""o. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Um fedor p""\xA3""trido paira no ar. Existem duas portas, levando ";
     gotoxy(2,g);g++;delay(250);
     cout<<"para o sul e oeste, respectivamente. Ao longo da parede ";
     gotoxy(2,g);g++;delay(250);
     cout<<"leste, voc""\x88"" pode ver cinco esqueletos acorrentados. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Presume-se que isso deva ser o que sobrou dos ""\xA3""ltimos cinco ";
     gotoxy(2,g);g++;delay(250);
     cout<<"aventureiros que por aqui passaram a pouco tempo atr""\xA0""s. Tr""\x88""s ";
     gotoxy(2,g);g++;delay(250);
     cout<<"arcas de madeira se encontram no ch""\xC6""o bem abaixo dos p""\x82""s ";
     gotoxy(2,g);g++;delay(250);
     cout<<"pendentes dos tr""\x88""s esqueletos centrais, respectivamente, cada ";
     gotoxy(2,g);g++;delay(250);
     cout<<"um abaixo de um esqueleto, e os dois esqueletos da extrema ";
     gotoxy(2,g);g++;delay(250);
     cout<<"direita e extrema esquerda n""\xC6""o tem arca abaixo de seus p""\x82""s. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Por estranho que pare""\x87""a, os dos esqueletos que n""\xC6""o est""\xC6""o com ";
     gotoxy(2,g);g++;delay(250);
     cout<<"uma arca abaixo de seus p""\x82""s est""\xC6""o faltando o cr""\x83""nio para ";
     gotoxy(2,g);g++;delay(250);
     cout<<"completar o esqueleto.";
     prison:{}
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,g);g++;delay(250);
     cout<<" ***APOSENTO 8*** ";
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Examinar os esqueletos";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Examinar as arcas de madeira";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Examinar as paredes";
     gotoxy(2,g);g++;delay(250);
     cout<<"4. Sair dessa sala";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 8*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" resolve tocar os esqueletos, quando voc""\x88"" est""\xA0"" chegando ";
              gotoxy(2,g);g++;delay(250);
              cout<<"perto do esqueleto voc""\x88"" percebe que as correntes se ";
              gotoxy(2,g);g++;delay(250);
              cout<<"movimentaram um pouco e fizeram um pequeno barulho de ";
              gotoxy(2,g);g++;delay(250);
              cout<<"correntes enferrujadas em atrito.";
              g++;gotoxy(2,g);g++;delay(250);
              cout<<"Deseja continuar a examinar os esqueletos?(S ou N)";
              go=getch();
              if(go=='s'||go=='S')
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" n""\xC6""o encontra nada ...";
              }
              goto prison;
         case 2:
	          if(arca==1)
	          {
                   gotoxy(2,22);g++;delay(250);
                   cout<<"Aperte qualquer tecla para continuar";
                   go=getch();
                   clrscr() ;menun(); g=2;
                   gotoxy(20,g);g++;delay(250);
                   cout<<" ***APOSENTO 8*** ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" j""\xA0"" fez isso e as arcas est""\xC6""o abertas. Nada se";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"encontra l""\xA0"" dentro.";
                   goto prison;
              }
              arca=1;
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 8*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Voce abre a primeira arca:";
              gotoxy(2,g);g++;delay(250);
              cout<<"A Arca est""\xA0"" aberta e voc""\x88"" pode ver o que lhe parece um ";
              gotoxy(2,g);g++;delay(250);
              cout<<"bast""\xC6""o m""\xA0""gico, tem uma forma cil""\xA1""ndrica e uma cor que ";
              gotoxy(2,g);g++;delay(250);
              cout<<"lembra madeira.";
              g++;gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" deseja pegar o bast""\xC6""o?(S ou N)";
              go=getch();
              if(go=='s'||go=='S')
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Quando voc""\x88"" coloca a m""\xC6""o sobre aquele bast""\xC6""o ";
                   gotoxy(2,g);g++;delay(250);
		           cout<<"voc""\x88"" nota que ele come""\x87""a a mudar de forma e se ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"transforma em uma serpente que lhe ataca.";
                   gotoxy(2,22);g++;delay(250);
                   cout<<"Aperte qualquer tecla para continuar";
                   go=getch();
                   clrscr() ;menun(); g=2;
                   enemy=2;
                   energy=fight();
                   if(energy<=0)
                   {
	                    goto dead;
                   }
              }
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 8*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Deseja abrir a pr""\xA2""xima arca?(S ou N)";
              go=getch();
              if(go=='n'||go=='N')
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Realmente ""\x82"" melhor deixar pra l""\xA0"".";
                   goto posarca;
              }
              gotoxy(2,g);g++;delay(250);
              cout<<"Na outra arca voc""\x88"" encontra apenas algumas";
              gotoxy(2,g);g++;delay(250);
              cout<<"moedas e um camundongo que morde seu dedo e corre";
              g++;gotoxy(2,g);g++;delay(250);
              cout<<"Deseja abrir a pr""\xA2""xima arca?(S ou N)";
              go=getch();
              if(go=='n'||go=='N')
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Realmente ""\x82"" melhor deixar pra l""\xA0"".";
                   goto posarca;
              }
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 8*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Quando voc""\x88"" consegue abrir a ""\xA3""ltima arca, um vulto ";
              gotoxy(2,g);g++;delay(250);
              cout<<"branco aparece de dentro da caixa, espalhando pelo ";
              gotoxy(2,g);g++;delay(250);
              cout<<"ambiente do aposento uma risada mal""\x82""fica e ";
              gotoxy(2,g);g++;delay(250);
              cout<<"assustadora, que ecoa pelo quarto enquanto voc""\x88"" v""\x88"" ";
              gotoxy(2,g);g++;delay(250);
              cout<<"aquela grande desloca""\x87""""\xC6""o de massa saindo de dentro ";
              gotoxy(2,g);g++;delay(250);
              cout<<"da caixa. Uma hora voc""\x88"" percebe que n""\xC6""o est""\xA0"" mais ";
              gotoxy(2,g);g++;delay(250);
              cout<<"saindo nada de dentro da caixa, e o som da risada ";
              gotoxy(2,g);g++;delay(250);
              cout<<"est""\xA0"" se dissipando. Voc""\x88"" est""\xA0"" amedrontado com esse ";
              gotoxy(2,g);g++;delay(250);
              cout<<"fato e por esse motivo tem -1 ponto de Habilidade enquanto";
              gotoxy(2,g);g++;delay(250);
              cout<<"estiver nessa sala.Quando voc""\x88"" acha que tudo isso";
              gotoxy(2,g);g++;delay(250);
              cout<<"passou, que voc""\x88"" olha para tr""\xA0""s, percebe que algo se";
              gotoxy(2,g);g++;delay(250);
              cout<<"formou atr""\xA0""s de voc""\x88"", pr""\xA2""ximo a porta Oeste, ""\x82"" uma ";
              gotoxy(2,g);g++;delay(250);
              cout<<"forma humana vestindo uma t""\xA3""nica que lhe tampa a ";
              gotoxy(2,g);g++;delay(250);
              cout<<"face, voc""\x88"" faz um esfor""\x87""o para lhe ver a face e ";
              gotoxy(2,g);g++;delay(250);
              cout<<"apenas v""\x88"" por dentro da t""\xA3""nica um maxilar, mas ";
              gotoxy(2,g);g++;delay(250);
              cout<<"reparando bem voc""\x88"" v""\x88"" que s""\xA2"" est""\xC6""o os ossos, como ";
              gotoxy(2,g);g++;delay(250);
              cout<<"se fosse um esqueleto.";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 8*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"O fantasma ent""\xC6""o lhe diz com uma voz grave e assustadora:";
              gotoxy(2,g);g++;delay(250);
              cout<<"- O que voc""\x88"" faz por aqui, e por que abriu a caixa ";
              gotoxy(2,g);g++;delay(250);
              cout<<"onde eu estava repousando? Todos que est""\xC6""o aqui ";
              gotoxy(2,g);g++;delay(250);
              cout<<"procuram pela morte, coloque todos os seus tesouros ";
              gotoxy(2,g);g++;delay(250);
              cout<<"na minha arca ou terminar""\xA0"" como os ""\xA3""ltimos cinco que";
              gotoxy(2,g);g++;delay(250);
              cout<<"vieram aqui (e aponta com seu indicador,formado ";
              gotoxy(2,g);g++;delay(250);
              cout<<"apenas por ossos, para os cinco esqueletos) ";
              gotoxy(2,g);g++;delay(250);
              cout<<"O que voc""\x88"" deseja fazer?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Atacar o fantasma";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. Colocar todo o seu ouro na arca.";
              g++;gotoxy(2,g);delay(250);
              cin>>op;
              if(op==2)
              {
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" obedece o fantasma e coloca todos o seu ouro dentro";
              gotoxy(2,g);g++;delay(250);
              cout<<"da arca e em seguida o fantasma desaparece da sala pela";
              gotoxy(2,g);g++;delay(250);
              cout<<"arca que veio, assim levando seu ouro com ele.";
              ouro=0;
              goto posarca;
              }
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" se precipita a frente do fantasma e ele o ataca";
              gotoxy(2,g);g++;delay(250);
              cout<<"derrepente voc""\x88"" sente um arrepio subindo sua espinha";
              gotoxy(2,g);g++;delay(250);
              cout<<"e o fantasma lhe diz:";
              gotoxy(2,g);g++;delay(250);
              cout<<"- Voc""\x88"" vai se arrepender por sua insol""\x88""ncia!!";
              gotoxy(2,g);g++;delay(250);
              cout<<"e desaparece dentro da arca que veio. Quando voc""\x88"" olha";
              gotoxy(2,g);g++;delay(250);
              cout<<"arca est""\xA0"" aberta e vazia.";
              posarca:{}
              goto prison;
         case 3:
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" examina as paredes... elas parecem ter uma";
              gotoxy(2,g);g++;delay(250);
              cout<<"textura muito agradavel, voc""\x88"" pensa que se ainda";
              gotoxy(2,g);g++;delay(250);
              cout<<"estiver vivo ao final voc""\x88"" pode usar no seu quarto.";
	          goto prison;
         case 4:
              g++;gotoxy(2,g);g++;delay(250);
              cout<<"Qual caminho deseja seguir?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Sul(para o aposento de Trushbeard)";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. Oeste";
              gotoxy(2,g);g++;delay(250);
              cin>>op;
              if(op==1)
              {
                   goto apos3b;
              }
              else
              {
                   goto aposento13;
              }
         default:
              gotoxy(2,18);g++;delay(250);
		      cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	          goto prison;
         }
	 g--;gotoxy(2,g);g++;delay(250);
         cout<<"As duas portas parecem estar abertas.";
         gotoxy(2,g);g++;delay(250);
         cout<<"qual caminho deseja seguir?";
         gotoxy(2,g);g++;delay(250);
         cout<<"1. Sul(para o aposento de Trushbeard)";
         gotoxy(2,g);g++;delay(250);
         cout<<"2. Oeste";
         cin>>op;
         if(op==1)
         {
              goto apos3b;
         }
         else
         {
              goto aposento13;
         }
     //fim do aposento 8///////////////////////////////////////////////////////
     //APOSENTO 13/////////////////////////////////////////////////////////////
     aposento13:{}
     aposent13=1;
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 13***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Este aposento ""\x82"" obviamente algum tipo de habita""\x87""""\xC6""o. H""\xA0"" uma mesa e";
     gotoxy(2,g);g++;delay(250);
     cout<<"uma cadeira em um dos cantos do aposento e uma cama em outro. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Portas levam a norte e leste do quarto; abaixo das portas ";
     gotoxy(2,g);g++;delay(250);
     cout<<"h""\xA0"" um peda""\x87""o de madeira que mais parece uma prote""\x87""""\xC6""o contra ratos. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Pendurada na parede sul h""\xA0"" quadro com uma pintura de um p""\x83""ntano, ";
     gotoxy(2,g);g++;delay(250);
     cout<<"duas espadas cruzadas, velhas e enferrujadas, e um instrumento ";
     gotoxy(2,g);g++;delay(250);
     cout<<"musical com formato parecido com um banjo, mas com o bra""\x87""o bem ";
     gotoxy(2,g);g++;delay(250);
     cout<<"mais alongado, ""\x82"" um instrumento comprido, e possui apenas 1 corda.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Um som de ronco chama a sua aten""\x87""""\xC6""o novamente para a cama que est""\xA0""";
     gotoxy(2,g);g++;delay(250);
     cout<<" no canto do quarto. Duas feias cabe""\x87""as de r""\x82""pteis surgem das ";
     gotoxy(2,g);g++;delay(250);
     cout<<"cobertas! Seus olhos piscam e abrem ao mesmo tempo e fitam voc""\x88"". ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Ele come""\x87""a a lentamente se levantar, e voc""\x88"" percebe que n""\xC6""o s""\xC6""o 2 ";
     gotoxy(2,g);g++;delay(250);
     cout<<"lagartos, e sim um calacorm ( uma criatura r""\x82""ptil que tem 2 ";
     gotoxy(2,g);g++;delay(250);
     cout<<"cabe""\x87""as ). As cabe""\x87""as ficam cochichando entre si enquanto olham. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"O Calacorm lhe diz:";
     gotoxy(2,g);g++;delay(250);
     cout<<"- Saia j""\xA0"" do meu aposento";
     calatk:{}
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 13***";
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Adentrar no quarto e tentar conversar com o calacorm.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Amiigooo.... amiiiiiigooooooo toma uma provis""\xC6""ozinha";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Atacar o calacorm";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
	          gotoxy(2,g);g++;delay(250);
	          cout<<"Quando voc""\x88"" entra no quarto o calacorm o encara com seus";
              gotoxy(2,g);g++;delay(250);
              cout<<"4 olhos e come""\x87""a a rastejar em sua dire""\x87""""\xC6""o... no inicio";
              gotoxy(2,g);g++;delay(250);
              cout<<"voc""\x88"" acredita que seja algum animal desprez""\xA1""vel, mas ele";
              gotoxy(2,g);g++;delay(250);
              cout<<"se levanta furioso e segue em sua dire""\x87""""\xC6""o atacando voc""\x88"".";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              enemy=3;
              energy=fight();
              if(energy<=0)
              {
	               goto dead;
              }
              go=getch();
              clrscr() ;menun(); g=2;
              break;
         case 2:
              gotoxy(2,g);g++;delay(250);
	          cout<<"Quando ele come""\x87""a a caminhar na sua dire""\x87""""\xC6""o e voc""\x88"" ";
              gotoxy(2,g);g++;delay(250);
              cout<<"arremessa uma de suas provisões, voc""\x88"" nota que ele persegue";
	          gotoxy(2,g);g++;delay(250);
              cout<<"a comida e acaba ficando de costas pra voc""\x88"".(essa ""\x82"" uma";
              gotoxy(2,g);g++;delay(250);
              cout<<"otima vantagem em uma luta por isso neste ataque voc""\x88""";
              gotoxy(2,g);g++;delay(250);
              cout<<"ganha uma vantagem por atacar o calacorm de costas)";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              hability=hability+3;
              enemy=3;
              energy=fight();
              if(energy<=0)
              {
	               goto dead;
              }
              hability=hability-3;
              go=getch();
              clrscr() ;menun(); g=2;
              break;
         case 3:
              hability++;
              enemy=3;
              energy=fight();
              if(energy<=0)
              {
	               goto dead;
              }
              hability--;
	          go=getch();
              clrscr() ;menun(); g=2;
         default:
              gotoxy(2,18);g++;delay(250);
              cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	          goto calatk;
     }
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 13***";
     gotoxy(2,g);g++;delay(250);
	 cout<<"Agora o calacorm est""\xA0"" morto.";
     gotoxy(2,g);g++;delay(250);
	 cout<<"Deseja examinar o aposento?(S ou N)";
     go=getch();
     if(go=='s'||go=='S')
     {
         g++;gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" examina o quarto...Ao examinar a parede com o quadro,";
         gotoxy(2,g);g++;delay(250);
         cout<<"voc""\x88"" percebe que o quadro est""\xA0"" um pouco descolado da parede, e ";
         gotoxy(2,g);g++;delay(250);
         cout<<"resolve tirar o quadro para ver se encontra algo.";
         gotoxy(2,g);g++;delay(250);
         cout<<"Ao retirar o quadro, voc""\x88"" encontra um pequeno buraco onde est""\xC6""o";
         gotoxy(2,g);g++;delay(250);
         cout<<"guardadas 6 moedas de ouro e um colar(25 moedas)";
         ouro=ouro+31;
     }
     g++;gotoxy(2,g);g++;delay(250);
	 cout<<"O que deseja fazer agora?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Seguir pela porta norte";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Seguir pela porta leste";
     gotoxy(2,g);g++;delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
              goto aposento14;
         case 2:
              goto apos8b;
     }
     //fim do aposento 13//////////////////////////////////////////////////////
     //aposento 14/////////////////////////////////////////////////////////////
     aposento14:{}
     aposent14=1;
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 14***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" est""\xA0"" em uma longa e fechada caverna de rocha. O aposento ";
     gotoxy(2,g);g++;delay(250);
     cout<<"""\x82"" quase retangular e, nos vincos rochosos de suas paredes, ";
     gotoxy(2,g);g++;delay(250);
     cout<<"existem pequenas fendas escuras. Ao todo s""\xC6""o 4 t""\xA3""neis. O t""\xA3""nel a ";
     gotoxy(2,g);g++;delay(250);
     cout<<"nordeste, o primeiro deles, da direita para a esquerda, ""\x82"" ";
     gotoxy(2,g);g++;delay(250);
     cout<<"guardado por uma brilhante teia de aranha, esticada sobre sua ";
     gotoxy(2,g);g++;delay(250);
     cout<<"entrada. A caverna ""\x82"" toda silencio, voc""\x88"" n""\xC6""o ouve quase nada.";
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     cave:{}
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 14***";
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Examinar as paredes do local.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Examinar o t""\xA3""nel guardado por uma teia de aranha.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Adentrar em um dos tr""\x88""s t""\xA3""neis.";
     gotoxy(2,g);g++;delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         if(Nandi==1)
         {
              gotoxy(20,2);g++;delay(250);
              cout<<"***APOSENTO 14***";
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" encontra o Nandi Bear morto e mais nada.";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              goto cave;
         }
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 14***";
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" foi em dire""\x87""""\xC6""o a parede nordeste e come""\x87""ou a tatear, ";
         gotoxy(2,g);g++;delay(250);
         cout<<"para ver se havia algo em comum, e nada encontrou. Continuou ";
         gotoxy(2,g);g++;delay(250);
         cout<<"tateando at""\x82"" chegar na parede sudeste, onde, voc""\x88"" foi";
         gotoxy(2,g);g++;delay(250);
         cout<<"surpreendido por um Nandi Bear ( uma criatura corpulenta,";
         gotoxy(2,g);g++;delay(250);
         cout<<"meio humana meio urso, que chega a ser maior que os 2 ).";
         gotoxy(2,g);g++;delay(250);
	     cout<<"Ele pula para cima de voc""\x88"" para lhe atacar.";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         enemy=4;
         Nandi=1;
         energy=fight();
         if(energy<=0)
         {
	      goto dead;
         }
         go=getch();
         clrscr();
         menun();
         g=2;
         goto cave;

         case 2:
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 14***";
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" chega at""\x82"" o t""\xA3""nel e olha bem a teia de aranha, ela ""\x82"" ";
         gotoxy(2,g);g++;delay(250);
         cout<<"brilhante, e voc""\x88"" pode deduzir que ela ""\x82"" bem forte.";
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" se aproxima da teia para tentar enchergar mais dentro ";
         gotoxy(2,g);g++;delay(250);
         cout<<"do t""\xA3""nel, quando de repente do nada voc""\x88"" ve uma pata de aranha";
         gotoxy(2,g);g++;delay(250);
         cout<<"saindo de dentro do tunel por entre a teia. A pata por pouco n""\xC6""o";
         gotoxy(2,g);g++;delay(250);
         cout<<"o acerta.Talvez deva ser melhor deixar esse tunel como est""\xA0""";
         gotoxy(2,g);g++;delay(250);
         cout<<"voc""\x88"" pensa.";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
	     goto cave;
         case 3:
         goto escolhas;

         default:
         gotoxy(2,18);g++;delay(250);
		 cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
	     goto cave;
         escolhas:{}
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 14***";
         gotoxy(2,g);g++;delay(250);
         cout<<"Qual t""\xA3""nel deseja seguir?";
         gotoxy(2,g);g++;delay(250);
         cout<<"1. O t""\xA3""nel da direita.";
         gotoxy(2,g);g++;delay(250);
         cout<<"2. O t""\xA3""nel do meio.";
         gotoxy(2,g);g++;delay(250);
         cout<<"3. O t""\xA3""nel da esquerda.";
         gotoxy(2,g);g++;delay(250);
         cout<<"4. Voltar ao aposento anterior";
         g++;gotoxy(2,g);delay(250);
         cin>>op;
         switch(op)
         {
         case 1:
              if(krystalkey==1)
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" adentra no t""\xA3""nel da direita.";
                   goto aposento15;
              }
              else
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" adentra no t""\xA3""nel que se mostra bem curto.";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"No final do Tunel voc""\x88"" encontra uma porta de madeira ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"maci""\x87""a com um emblema da cabe""\x87""a de um demônio esculpida";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"em seu centro, e na boca do Demonio voc""\x88"" ve um buraco";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"que lembra uma fechadura.";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" tenta abrir a porta e ela est""\xA0"" trancada";
                   gotoxy(2,g);g++;delay(250);
                   goto escolhas;
              }
         case 2:
              if(aposent16==1)
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" adentra no t""\xA3""nel do meio.";
                   goto aposento17;
              }
              else
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" adentra no t""\xA3""nel central e se depara com uma porta";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"de madeira maci""\x87""a, com detalhes de ouro, parecendo bem";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"luxuosa. A porta ""\x82"" bem pesada e n""\xC6""o h""\xA0"" ma""\x87""anetas ou ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"outro objeto que poderia ser usado para abri-la.";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" percebe que n""\xC6""o conseguir""\xA0"" abrir a porta apenas ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"com as m""\xC6""os e retorna a caverna.";
                   gotoxy(2,g);g++;delay(250);
                   goto escolhas;
              }
         case 3:
              if(aposent17==1)
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" adentra no t""\xA3""nel da esquerda.";
                   goto aposento18;
              }
              else
              {
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" entra no pequeno t""\xA3""nel e se depara com uma porta negra com 3 ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"desenhos dourados e brilhantes. S""\xC6""o eles, uma lua, um sol e uma ";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"estrela. Os tr""\x88""s est""\xC6""o nas pontas de um triangulo.";
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Esta porta est""\xA0"" trancada";
                   goto escolhas;
              }
         case 4:
              goto apos13b;
         }
     }
     gotoxy(2,g);g++;delay(250);
     cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
     goto escolhas;
     //fim do aposento14///////////////////////////////////////////////////////
     //aposento 15/////////////////////////////////////////////////////////////
     aposento15:{}
     aposent15=1;
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 15***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" adentra no t""\xA3""nel que se mostra bem curto.";
     gotoxy(2,g);g++;delay(250);
     cout<<"No final do Tunel voc""\x88"" encontra uma porta de madeira ";
     gotoxy(2,g);g++;delay(250);
     cout<<"maci""\x87""a com um emblema da cabe""\x87""a de um demônio esculpida";
     gotoxy(2,g);g++;delay(250);
     cout<<"em seu centro, e na boca do Demonio voc""\x88"" ve um buraco";
     gotoxy(2,g);g++;delay(250);
     cout<<"que lembra uma fechadura.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" ent""\xC6""o introduz a chave de cristal que o Nandras lhe deu";
     gotoxy(2,g);g++;delay(250);
     cout<<"e a porta se destranca.";
     cerberus:{}
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 15***";
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Abrir a porta para tentar enxergar algo l""\xA0"" dentro.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Acender a lamparina e tentar enxergar algo dentro da sala.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Voltar a caverna anterior.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
         aposent15=1;
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" abre a porta, e tenta enxergar algo em meio a escurid""\xC6""o,";
         gotoxy(2,g);g++;delay(250);
         cout<<"voc""\x88"" n""\xC6""o sabe qual ""\x82"" o tamanho do aposento, e nem mesmo se ";
         gotoxy(2,g);g++;delay(250);
         cout<<"""\x82"" um aposento. De repente, em meio a escurid""\xC6""o voc""\x88"" v""\x88"" dois ";
         gotoxy(2,g);g++;delay(250);
         cout<<"pontos vermelhos de luz aparecendo em meio ao breu total.";
         g++;gotoxy(2,g);g++;delay(250);
         cout<<"Deseja entrar no aposento? (S ou N)";
         go=getch();
         if(go=='s'||go=='S')
         {
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" ve os pontos vindo em sua dire""\x87""""\xC6""o e ouve rosnados";
              gotoxy(2,g);g++;delay(250);
              cout<<"voc""\x88"" n""\xC6""o sabe o que ""\x82"", mas parece estar muito bravo e";
              gotoxy(2,g);g++;delay(250);
	          cout<<"vem em sua dire""\x87""""\xC6""o. Melhor se defender.";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              enemy=5;
              energy=fight();
              if(energy<=0)
              {
	               goto dead;
              }
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,2);g++;delay(250);
              cout<<"***APOSENTO 15***";
              gotoxy(2,g);g++;delay(250);
              cout<<"O cerberus morre e o quaro clareia, voc""\x88"" ve duas portas";
              gotoxy(2,g);g++;delay(250);
              cout<<"uma delas (Porta sul) ""\x82"" a porta cujo voc""\x88"" usou para chegar";
              gotoxy(2,g);g++;delay(250);
              cout<<"at""\x82"" aqui, e a ourta est""\xA0"" localizada na parede norte.";
              g++;gotoxy(2,g);g++;delay(250);
              portcerb:{}
              cout<<"O que deseja fazer?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Seguir pela porta norte";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. Seguir pela porta sul";
              g++;gotoxy(2,g);delay(250);
              cin>>op;
              switch(op)
              {
		      case 1:
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" segue pela porta norte";
                   goto aposento16;
              case 2:
                   gotoxy(2,g);g++;delay(250);
                   cout<<"Voc""\x88"" segue pela porta sul";
                   goto apos14b;
              default:
                   gotoxy(2,18);g++;delay(250);
		           cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                   gotoxy(2,22);g++;delay(250);
                   cout<<"Aperte qualquer tecla para continuar";
                   go=getch();
                   clrscr() ;menun(); g=2;
                   gotoxy(20,2);g++;delay(250);
                   cout<<"***APOSENTO 15***";
                   gotoxy(2,g);g++;delay(250);
	               goto portcerb;
              }
              }
         case 2:
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" acende a lamparina e tenta ver por entre a porta que ";
              gotoxy(2,g);g++;delay(250);
              cout<<"est""\xA0"" meio aberta, mas nada muda, ""\x82"" como se a lamparina ";
              gotoxy(2,g);g++;delay(250);
              cout<<"estivesse apagada.";
              goto cerberus;
         case 3:
              goto apos14b;
     }
     goto cerberus;
     //fim do aposento 15//////////////////////////////////////////////////////
     //APOSENTO 16/////////////////////////////////////////////////////////////
     aposento16:{}
     aposent16=1;
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 16***";
     gotoxy(2,g);g++;delay(250);
     cout<<"A n""\xC6""o ser por uma mesa encostada na parede norte, o aposento se ";
     gotoxy(2,g);g++;delay(250);
     cout<<"encontra vazio. Duas velas, fixadas na mesma parede da mesa, se ";
     gotoxy(2,g);g++;delay(250);
     cout<<"acenderam quando voc""\x88"" entrou, assim iluminando o aposento. H""\xA0"" ";
     gotoxy(2,g);g++;delay(250);
     cout<<"sobre a mesa um livro com capa de couro preta com 2 finas faixas ";
     gotoxy(2,g);g++;delay(250);
     cout<<"brancas como borda ao seu redor. N""\xC6""o existe outra porta no ";
     gotoxy(2,g);g++;delay(250);
     cout<<"aposento, somente aquela pela qual voc""\x88"" entrou";
     gotoxy(2,g);g++;delay(250);
     bookmenu:{}
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Examinar as paredes desse aposento.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Abrir o livro e l""\x88""-lo.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Voltar ao aposento anterior.";
     gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" come""\x87""ou a examinar as paredes desse aposento, primeiramente";
         gotoxy(2,g);g++;delay(250);
         cout<<"examinou a parede leste, e nada encontrou, voc""\x88"" olhou para a ";
         gotoxy(2,g);g++;delay(250);
	     cout<<"parede norte, mas ela estava quase toda ocupada pela mesa e as ";
         gotoxy(2,g);g++;delay(250);
         cout<<"velas, ent""\xC6""o voc""\x88"" foi examinar a parede oeste. Na parede oeste";
         gotoxy(2,g);g++;delay(250);
         cout<<"voc""\x88"" encontrou um buraco pequeno, onde passaria apenas sua m""\xC6""o,";
         gotoxy(2,g);g++;delay(250);
         cout<<"ent""\xC6""o voc""\x88"" acendeu a lamparina para ver melhor esse buraco, mas";
         gotoxy(2,g);g++;delay(250);
         cout<<"era apenas um buraco comum que n""\xC6""o lhe dizia nada de ";
         gotoxy(2,g);g++;delay(250);
         cout<<"interessante.";
         livro:{}
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 16***";
         gotoxy(2,g);g++;delay(250);
         cout<<"O que deseja fazer agora?";
         gotoxy(2,g);g++;delay(250);
         cout<<"1. Ler o livro.";
         gotoxy(2,g);g++;delay(250);
         cout<<"2. Voltar pela porta de onde veio";
         g++;gotoxy(2,g);delay(250);
         cin>>op;
         switch(op)
         {
	          case 1:
                   goto brokenseal;
              case 2:
                   goto apos15b;
              default:
                   gotoxy(2,g);g++;delay(250);
                   cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                   goto livro;
         }
         case 2:
         brokenseal:{}
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" se aproxima do livro e o abre...Quanto o livro ""\x82"" aberto,";
         gotoxy(2,g);g++;delay(250);
         cout<<"voc""\x88"" ouve um gemido grave no ar, e percebe que um zumbi";
         gotoxy(2,g);g++;delay(250);
         cout<<"acaba de aparecer no canto noroeste do quarto e est""\xA0"" vindo em";
         gotoxy(2,g);g++;delay(250);
         cout<<"sua dire""\x87""""\xC6""o para atac""\xA0""-lo.";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         enemy=6;
         energy=fight();
         if(energy<=0)
         {
	      goto dead;
         }
         go=getch();
         clrscr() ;menun(); g=2;
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 16***";
         gotoxy(2,g);g++;delay(250);
         cout<<"Agora que o zumbi est""\xA0"" morto voc""\x88"" come""\x87""a a ler o Livro.";
         gotoxy(2,g);g++;delay(250);
         cout<<"Logo voc""\x88"" nota que se trata de um livro de feiti""\x87""os, mas grande";
         gotoxy(2,g);g++;delay(250);
         cout<<"parte dele est""\xA0"" muito alem das suas habilidades. Apesar da ";
         gotoxy(2,g);g++;delay(250);
         cout<<"estranha escrita voc""\x88"" consegue distinguir algumas coisas nele";
         gotoxy(2,g);g++;delay(250);
         cout<<"at""\x82"" que encontra uma pagina com dois feiti""\x87""os que talvez voc""\x88"" ";
         gotoxy(2,g);g++;delay(250);
         cout<<"possa usar. Eles s""\xC6""o todos em uma lingua estranha, mas h""\xA0"" certas";
         gotoxy(2,g);g++;delay(250);
         cout<<"palavras que voc""\x88"" compreende.S""\xC6""o dois grupos de palavras, talvez";
         gotoxy(2,g);g++;delay(250);
         cout<<"sejam dois feiti""\x87""os diferentes, voc""\x88"" olha atentamente ao ";
         gotoxy(2,g);g++;delay(250);
	     cout<<"primeiro grupo de palavras.";
         gotoxy(2,g);g++;delay(250);
	     cout<<"Deseja dizer as palavras magicas? (S ou N)";
         go=getch();
         if(go=='s'||go=='S')
         {
         gotoxy(2,g);g++;delay(250);
         cout<<"Quando voc""\x88"" as diz voc""\x88"" ve uma explos""\xC6""o e luzes brilhantes";
         gotoxy(2,g);g++;delay(250);
         cout<<"atravessando a sala, parecem fogos de artificio, talvez seja";
         gotoxy(2,g);g++;delay(250);
         cout<<"um feiti""\x87""o para animar festas, mas a claridade doi no seu";
         gotoxy(2,g);g++;delay(250);
         cout<<"olho.";
         }
         gotoxy(2,g);g++;delay(250);
         cout<<"Deseja dizer o segundo grupo de palavras? (S ou N)";
         go=getch();
         if(go=='s'||go=='S')
         {
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" v""\x88"" alguma coisa parecendo uma onda de vento percorrendo o";
	     gotoxy(2,g);g++;delay(250);
         cout<<"aposento e se espalhando pela sala anterior e ouve o barulho de";
         gotoxy(2,g);g++;delay(250);
         cout<<"trinco como se uma porta tivesse sido aberta.";
         brokenseal=1;
         }
         goto livro;
         case 3:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" volta pela porta de onde veio ";
         goto apos15b;
         default:
         gotoxy(2,18);g++;delay(250);
		 cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 16***";
         gotoxy(2,g);g++;delay(250);
	     goto bookmenu;
     }
     //fim do aposento 16//////////////////////////////////////////////////////
     //APOSENTO 17/////////////////////////////////////////////////////////////
     aposento17:{}
     aposent17=1;
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 17***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" adentra no t""\xA3""nel central e se depara com uma porta";
     gotoxy(2,g);g++;delay(250);
     cout<<"de madeira maci""\x87""a, com detalhes de ouro, parecendo bem";
     gotoxy(2,g);g++;delay(250);
     cout<<"luxuosa. A porta est""\xA0"" apenas encostada e pode ser aberta com um ";
     gotoxy(2,g);g++;delay(250);
     cout<<"um leve empurr""\xC6""o. Ap""\xA2""s entrar no aposento voc""\x88"" se depara com";
     gotoxy(2,g);g++;delay(250);
     cout<<"um aposento prodigamente decorado com ricas cortinas.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Pendendo de cada canto do teto existem teias douradas em formato";
     gotoxy(2,g);g++;delay(250);
     cout<<"de rede, que fazem um bonito arranjo no aposento. Esta ""\x82"" a sala ";
     gotoxy(2,g);g++;delay(250);
     cout<<"do trono do Rei aranha!! Sentado – ou,melhor dizendo, acocorado – ";
     gotoxy(2,g);g++;delay(250);
     cout<<"no canto mais distante do aposento, em um banco feito à m""\xC6""o, est""\xA0"" ";
     gotoxy(2,g);g++;delay(250);
     cout<<"o rei aranha em pessoa: Uma criatura feia e corpulenta, com corpo ";
     gotoxy(2,g);g++;delay(250);
     cout<<"de aranha e cabe""\x87""a de homem. intruso impudente Grita ele. ";
     gotoxy(2,g);g++;delay(250);
     cout<<"Curve-se at""\x82"" o ch""\xC6""o diante do rei aranha!!";
     menuaranha:{}
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 17***";
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Fugir do rei aranha.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Curvar-se diante do rei aranha.";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Atacar o rei aranha.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" tenta se virar para correr mas o rei aranha joga uma teia";
         gotoxy(2,g);g++;delay(250);
         cout<<"bem estranha em voc""\x88"" que impede qualquer movimento.";
         gotoxy(2,g);g++;delay(250);
         cout<<"Com muito esfor""\x87""o voc""\x88"" consegue escapar mas pelo esfor""\x87""o voc""\x88""";
         gotoxy(2,g);g++;delay(250);
         cout<<"acaba perdendo 1 um ponto de vida.";
	     energy--;
         gotoxy(2,g);g++;delay(250);
         cout<<"E quando sai voc""\x88"" v""\x88"" o rei aranha vindo em sua dire""\x87""""\xC6""o para";
         gotoxy(2,g);g++;delay(250);
         cout<<"te atacar. Melhor defender-se.";
         gotoxy(2,20);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         enemy=7;
         energy=fight();
         if(energy<=0)
         {
	      goto dead;
         }
         go=getch();
         clrscr() ;menun(); g=2;
         break;

         case 2:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" se curva diante do rei aranha. O rei aranha diz: ";
         gotoxy(2,g);g++;delay(250);
         cout<<"-Intruso imprudente, mas inteligente...O que procura aqui?";
         gotoxy(2,g);g++;delay(250);
         cout<<"O que deseja responder ao rei aranha?";
         menuaranha2:{}
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         gotoxy(20,2);g++;delay(250);
         cout<<"***APOSENTO 17***";
	     gotoxy(2,g);g++;delay(250);
         cout<<"1. Eu procuro um tesouro que est""\xA0"" escondido nesta masmorra.";
         gotoxy(2,g);g++;delay(250);
         cout<<"2. Eu estou apenas andando pela masmorra, estou curioso";
         gotoxy(2,g);g++;delay(250);
         cout<<"quanto aos aposentos.";
         g++;gotoxy(2,g);delay(250);
         cin>>op;
         switch(op)
         {
              case 1:
              gotoxy(2,g);g++;delay(250);
              cout<<"O rei aranha diz: Para conseguir o tesouro voc""\x88"" vi ter ";
              gotoxy(2,g);g++;delay(250);
              cout<<"que passar por cima do rei aranha!!! Defenda-se!! E o ";
              gotoxy(2,g);g++;delay(250);
              cout<<"rei aranha vem em sua dire""\x87""""\xC6""o para ataca-lo.";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              enemy=7;
              energy=fight();
              if(energy<=0)
              {
	               goto dead;
              }
              go=getch();
              clrscr() ;menun(); g=2;
              break;

              case 2:
              gotoxy(2,g);g++;delay(250);
              cout<<"O rei aranha diz:  Pobre infeliz....Sua curiosidade o ";
              gotoxy(2,g);g++;delay(250);
              cout<<"levar""\xA0"" a morte!! Defenda-se!! E o rei aranha vem em sua ";
              gotoxy(2,g);g++;delay(250);
              cout<<"dire""\x87""""\xC6""o para atac""\xA0""-lo.";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              enemy=7;
              energy=fight();
              if(energy<=0)
              {
	               goto dead;
              }
              go=getch();
              clrscr();
              menun();
              g=2;
              break;

              default:
              gotoxy(2,g);g++;delay(250);
              cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
              goto menuaranha2;
         }
         goto posrei;
	 case 3:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" desembainha sua espada e parte em dire""\x87""""\xC6""o ao rei aranha ";
         gotoxy(2,g);g++;delay(250);
         cout<<"para atac""\xA0""-lo. Antes que chegue perto do rei aranha ele lhe ";
         gotoxy(2,g);g++;delay(250);
         cout<<"dispara uma teia bem parecida com aquela que est""\xA0"" na caverna ";
         gotoxy(2,g);g++;delay(250);
         cout<<"onde voc""\x88"" estava anteriormente. Voc""\x88"" tenta escapar da teia, ";
         gotoxy(2,g);g++;delay(250);
         cout<<"mas ""\x82"" bem dif""\xA1""cil. Sua espada n""\xC6""o consegue corta-la com ";
         gotoxy(2,g);g++;delay(250);
         cout<<"facilidade. Enquanto voc""\x88"" tenta escapar da teia o rei aranha ";
         gotoxy(2,g);g++;delay(250);
         cout<<"lhe diz: -""\x90"" isso que merece pela sua insol""\x88""ncia!! ";
         gotoxy(2,g);g++;delay(250);
         cout<<"Com muito esfor""\x87""o voc""\x88"" consegue sair da teia, e devido a tal ";
         gotoxy(2,g);g++;delay(250);
         cout<<"esfor""\x87""o voc""\x88"" perde 1 ponto de energia. Quando voc""\x88"" finalmente sai da ";
         gotoxy(2,g);g++;delay(250);
	     cout<<"teia voc""\x88"" v""\x88"" o rei aranha vindo em sua dire""\x87""""\xC6""o para lhe atacar.";
         gotoxy(2,22);g++;delay(250);
         cout<<"Aperte qualquer tecla para continuar";
         go=getch();
         clrscr() ;menun(); g=2;
         enemy=7;
         energy=fight();
         if(energy<=0)
         {
	      goto dead;
         }
         go=getch();
         clrscr() ;menun(); g=2;
         break;

         default:
         gotoxy(2,18);g++;delay(250);
		 cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
	     goto menuaranha;
     }
     posrei:{}
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 17***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Ao derrotar o rei aranha, ele cai ao ch""\xC6""o e lhe diz com suas ";
     gotoxy(2,g);g++;delay(250);
     cout<<"ultimas palavras: -Voc""\x88"" ""\x82"" um guerreiro honrado e merece o tesouro, ";
     gotoxy(2,g);g++;delay(250);
     cout<<"voc""\x88"" conseguiu derrotar o grande rei aranha! E ali o rei aranha morre.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Ap""\xA2""s a morte do rei aranha voc""\x88"" ouve um som estanho vindo da caverna";
     gotoxy(2,g);g++;delay(250);
     cout<<"e logo em seguida um barulho de trinco novamente.";
     spider:{}
     gotoxy(2,22);g++;delay(250);
     cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr() ;menun(); g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 17***";
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Explorar as paredes do aposento do rei aranha";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Explorar o trono";
     gotoxy(2,g);g++;delay(250);
     cout<<"3. Sair do aposento.";
     g++;gotoxy(2,g);delay(250);
     cin>>op;
     switch(op)
     {
         case 1:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" n""\xC6""o encontra nada de interessante s""\xA2"" a textura.";
         goto spider;
         case 2:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" encontra uma caixa com uma tarantula desenhada.";
         gotoxy(2,g);g++;delay(250);
         cout<<"O que deseja fazer?";
         gotoxy(2,g);g++;delay(250);
	     cout<<"1. Colocar a caixa na mochila";
         gotoxy(2,g);g++;delay(250);
         cout<<"2. Deixar onde est""\xA0""";
         gotoxy(2,g);g++;delay(250);
         cout<<"3. Abrir a caixa";
         g++;gotoxy(2,g);delay(250);
         cin>>op;
         switch(op)
         {
         case 1:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" guarda a caixa na mochila e continua seguindo o seu ";
         gotoxy(2,g);g++;delay(250);
         cout<<"caminho.";
         kinghorn=1;
         goto spider;
         case 2:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" deixa a caixa em cima do trono";
         kinghorn=1;
         goto spider;
	     case 3:
         gotoxy(2,g);g++;delay(250);
         cout<<"Voc""\x88"" resolve abrir a caixa, ent""\xC6""o voc""\x88"" usa a sua espada para ";
         gotoxy(2,g);g++;delay(250);
         cout<<"quebrar o cadeado que mantem a caixa fechada";
         gotoxy(2,g);g++;delay(250);
         cout<<"Dentro dela voc""\x88"" encontra algumas moedas de ouro e um objeto";
         gotoxy(2,g);g++;delay(250);
         cout<<"estranho recoberto por um material viscozo que voc""\x88"" n""\xC6""o ";
         gotoxy(2,g);g++;delay(250);
         cout<<"consegue identificar, quando voc""\x88"" se aproxima do objeto algo";
         gotoxy(2,g);g++;delay(250);
         cout<<"parecido com uma garra sai e pica sua pele fazendo com que";
         gotoxy(2,g);g++;delay(250);
         cout<<"solte a caixa. voc""\x88"" come""\x87""a a ficar tonto e desmaia";
         gotoxy(2,g);g++;delay(1250);
         cout<<"algumas horas depois voc""\x88"" acorda se sentindo estranho, voc""\x88""";
         gotoxy(2,g);g++;delay(250);
         cout<<"nota que n""\xC6""o tem mais controle sobre seus movimentos e seus";
         gotoxy(2,g);g++;delay(250);
	     cout<<"pensamentos est""\xC6""o confusos, voc""\x88"" nota ainda que agora possui";
         gotoxy(2,g);g++;delay(250);
         cout<<"patas.voc""\x88"" as conta...s""\xC6""o 8, derrepente uma voz na sua cabe""\x87""a";
         gotoxy(2,g);g++;delay(250);
         cout<<"diz algo pra voc""\x88"", inicialmente voc""\x88"" n""\xC6""o consegue entender";
         gotoxy(2,g);g++;delay(250);
         cout<<"mas as palavras v""\xC6""o tomando sentido e voc""\x88"" entende o que a voz";
         gotoxy(2,g);g++;delay(250);
         cout<<"diz:";
         gotoxy(2,g);g++;delay(250);
         cout<<"VOC""\x88"" VEIO A ESTE POÇO EM BUSCA DE TESOUROS E RIQUEZAS, E AGORA";
         gotoxy(2,g);g++;delay(250);
         cout<<"ELAS SÃO SUAS... TUDO AQUI EMBAIXO ""\x90"" SEU AGORA";
         gotoxy(2,g);g++;delay(250);
         cout<<"TODOS SE CURVARÃO NA SUA FRENTE E O RESPEITAR""\xC6""O...";
         gotoxy(2,g);g++;delay(250);
         cout<<"TODOS SE CURVAM DIANTE DO REI ARANHA.";
	     goto fim;
         }
	 case 3:
	      goto apos14b;
     }
     //Fim do aposento 17//////////////////////////////////////////////////////
     //essa parte ""\x82"" destinada a uma passagem pela segunda vez em cada aposento/
     //////////////////////////////////////////////////////////////////////////
     gato:{}
     switch(op)
     {
         case 1:
              apos3b:{}
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 3*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" ve Trushbeard sentado no canto do aposento...";
              gotoxy(2,g);g++;delay(250);
              cout<<"tudo est""\xA0"" exatamentente como estava da ultima vez que ";
              gotoxy(2,g);g++;delay(250);
              cout<<"voc""\x88"" esteve por aqui.";
              gotoxy(2,g);g++;delay(250);
              cout<<"ThrushBeard diz:";
              gotoxy(2,g);g++;delay(250);
              cout<<"- Voc""\x88"" aqui denovo ... bom ... fique a vontade";
              apos3bo:{}
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              apos3portas:{}
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 3*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Qual porta deseja seguir?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Leste";
	          gotoxy(2,g);g++;delay(250);
              cout<<"2. Norte";
              gotoxy(2,g);g++;delay(250);
              cout<<"3. Sul";
              g++;gotoxy(2,g);delay(250);
              cin>>op;
              switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta leste";
                        if(aposent4==1)
                        {
                        goto apos4b;
                        }
                        goto aposento4;
                   case 2:
                        gotoxy(2,18);g++;delay(250);
			            cout<<"Voc""\x88"" seguiu pela porta norte";
                        if(aposent8==1)
                        {
                        goto apos8b;
                        }
                        goto aposento8;
                   case 3:
			            gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" tenta abrir a porta, mas ela parece estar";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"trancada. Voc""\x88"" olha para ThrushBeard e ele lhe ";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"faz um sinal onde parece n""\xC6""o saber o por que.";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" ent""\xC6""o esquece isso e espera para resolver";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"mais tarde quando for necess""\xA0""rio usar a sa""\xA1""da.";
                        gotoxy(2,22);g++;delay(250);
                        cout<<"Aperte qualquer tecla para continuar";
                        go=getch();
                        clrscr() ;menun(); g=2;
                        goto apos3portas;
                   default:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        goto apos3bo;
              }
         //apos4b
         case 2:
              apos4b:{}
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 4*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" retorna ao aposento com o retrato de Marg e v""\x88""";
              gotoxy(2,g);g++;delay(250);
              cout<<"o retrato na parede, que lhe parece comum. Os items est""\xC6""o";
              gotoxy(2,g);g++;delay(250);
              cout<<"como voc""\x88"" os deixou da ultima vez que passou por aqui.";
	          gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 4*** ";
              gotoxy(2,g);g++;delay(250);
              apos4bo:{}
              cout<<"Qual porta deseja seguir?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Oeste";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. Leste";
	          gotoxy(2,g);g++;delay(250);
              cout<<"3. Norte";
              gotoxy(2,g);g++;delay(250);
              cin>>op;
              switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
			            cout<<"Voc""\x88"" seguiu pela porta oeste";
                        if(aposent3==1)
                        {
                             goto apos3b;
                        }
                        goto aposento3;
                   case 2:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta leste";
                        if(aposent5==1)
                        {
                             goto apos5b;
                        }
			            goto aposento5;
                   case 3:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta norte";
                        if(aposent6==1)
                        {
                             goto apos6b;
			}
                        goto aposento6;
                   default:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        clrscr() ;menun(); g=2;
                        gotoxy(20,g);g++;delay(250);
                        cout<<" ***APOSENTO 4*** ";
                        gotoxy(2,g);g++;delay(250);
                        goto apos4bo;
              }
	  //apos5b
	      case 3:
              apos5b:{}
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
	          cout<<" ***APOSENTO 5*** ";
              if(krystalkey==1)
              {
              gotoxy(2,g);g++;delay(250);
              cout<<"O aposento est""\xA0"" exatamente como estava quando voc""\x88"" passou";
              gotoxy(2,g);g++;delay(250);
              cout<<"pela ultima vez";
              }
              else
              {
              if(aposent6==1&&aposent4==1)
              {
              gotoxy(2,g);g++;delay(250);
	          cout<<"Voc""\x88"" encontra a sala vazia e uma chave de cristal no ch""\xC6""o";
              krystalkey=1;
              }
              else
              {
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" ouve a voz de Nandras lembrando do seu acordo";
	          }
              }
              apos5bo:{}
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
	          cout<<" ***APOSENTO 5*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"O que deseja fazer?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Sair do aposento.";
	          gotoxy(2,g);g++;delay(250);
              cout<<"2. Vasculhar o aposento.";
              gotoxy(2,g);g++;delay(250);
              cin>>op;
              switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" saiu do aposento.";
                        goto apos4b;

		           case 2:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" nada encontra.";
                        goto apos5bo;

                   default:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        goto apos5bo;
              }
	 //apos6b
	      case 4:
              apos6b:{}
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
	          cout<<" ***APOSENTO 6*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"O aposento est""\xA0"" exatamente como estava quando voc""\x88"" passou";
              gotoxy(2,g);g++;delay(250);
              cout<<"pela ultima vez";
              apos6bo:{}
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              gotoxy(20,2);g++;delay(250);
              cout<<"***APOSENTO 6***";
              gotoxy(2,g);g++;delay(250);
              cout<<"O que deseja fazer?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Sair do aposento.";
	          gotoxy(2,g);g++;delay(250);
              cout<<"2. Vasculhar o aposento.";
              gotoxy(2,g);g++;delay(250);
              cin>>op;
              switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" saiu do aposento.";
                        goto apos4b;

		           case 2:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" nada encontra.";
                        goto apos6bo;

                   default:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        goto apos6bo;
              }
         //apos8b
         case 5:
              apos8b:{}
              clrscr() ;menun(); g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 8*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"o aposento est""\xA0"" exatamente como estava quando voc""\x88"" passou";
              gotoxy(2,g);g++;delay(250);
              cout<<"pela ultima vez";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              apos8bo:{}
              gotoxy(20,2);g++;delay(250);
              cout<<"***APOSENTO 8***";
              gotoxy(2,g);g++;delay(250);
              cout<<"Qual porta deseja seguir?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Sul";
	          gotoxy(2,g);g++;delay(250);
              cout<<"2. Leste";
              gotoxy(2,g);g++;delay(250);
              cin>>op;
              switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta sul";
                        if(aposent3==1)
                        {
                             goto apos3b;
                        }
                        goto aposento3;
                   case 2:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta leste";
                        if(aposent13==1)
                        {
                             goto apos13b;
                        }
			            goto aposento13;
                   default:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        clrscr();
                        menun();
                        g=2;
                        goto apos8bo;
              }
         //apos13b
         case 6:
              apos13b:{}
              clrscr() ;menun(); g=2;
	          gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 13*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"O aposento est""\xA0"" exatamente como estava quando voc""\x88"" passou";
              gotoxy(2,g);g++;delay(250);
              cout<<"pela ultima vez";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              apos13bo:{}
              gotoxy(20,2);g++;delay(250);
              cout<<"***APOSENTO 13***";
	          gotoxy(2,g);g++;delay(250);
              cout<<"Qual porta deseja seguir?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Oeste";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. Norte";
              gotoxy(2,g);g++;delay(250);
              cin>>op;
	          switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta oeste";
                        if(aposent8==1)
                        {
                             goto apos8b;
                        }
                        goto aposento8;
                   case 2:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta Norte";
			            if(aposent14==1)
                        {
                             goto apos14b;
                        }
                        goto aposento14;
                   default:
                        gotoxy(2,18);g++;delay(250);
			            cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        clrscr() ;menun(); g=2;
                        goto apos13bo;
              }
              //apos14b
         case 7:
	          apos14b:{}
              clrscr();
              menun();
              g=2;
              gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 14*** ";
              gotoxy(2,g);g++;delay(250);
	          cout<<"Voc""\x88"" retorna a caverna, e ela est""\xA0"" exatamente como estava";
              gotoxy(2,g);g++;delay(250);
              cout<<"quando voc""\x88"" passou pela ultima vez";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              apos14bo:{}
              gotoxy(20,2);g++;delay(250);
              cout<<"***APOSENTO 14***";
              gotoxy(2,g);g++;delay(250);
              cout<<"Qual dos caminhos deseja seguir?";
              gotoxy(2,g);g++;delay(250);
	          cout<<"1. T""\xA3""nel da direita";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. T""\xA3""nel do meio";
              gotoxy(2,g);g++;delay(250);
              cout<<"3. T""\xA3""nel da esquerda";
              gotoxy(2,g);g++;delay(250);
              cout<<"4. Porta sul";
              gotoxy(2,g);g++;delay(250);
	          cin>>op;
              switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pelo t""\xA3""nel da direita";
                        if(aposent15==1)
                        {
                             goto apos15b;
                        }
                        if(krystalkey==1)
                        {
                             goto aposento15;
                        }
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" adentra no t""\xA3""nel que se mostra bem curto.";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"No final do Tunel voc""\x88"" encontra uma porta de madeira ";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"maci""\x87""a com um emblema da cabe""\x87""a de um demônio esculpida";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"em seu centro, e na boca do Demonio voc""\x88"" ve um buraco";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"que lembra uma fechadura.";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" tenta abrir a porta e ela est""\xA0"" trancada";
                        gotoxy(2,g);g++;delay(250);
                        goto apos14b;
                   case 2:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pelo t""\xA3""nel do meio";
                        if(aposent16==1&&aposent17==1)
                        {
                             goto apos17b;
                        }
			            if(aposent16==1&&brokenseal==1)
                        {
                             goto aposento17;
                        }
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" adentra no t""\xA3""nel central e se depara com uma porta";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"de madeira maci""\x87""a, com detalhes de ouro, parecendo bem";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"luxuosa. A porta ""\x82"" bem pesada e n""\xC6""o h""\xA0"" ma""\x87""anetas ou ";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"outro objeto que poderia ser usado para abri-la.";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" percebe que n""\xC6""o conseguir""\xA0"" abrir a porta apenas ";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"com as m""\xC6""os e retorna a caverna.";
                        gotoxy(2,g);g++;delay(250);
                        goto apos14b;
                   case 3:
                        if(aposent17==1)
                        {
                             gotoxy(2,18);g++;delay(250);
                             cout<<"Voc""\x88"" seguiu pelo t""\xA3""nel da esquerda";
                             gotoxy(2,22);g++;delay(250);
                             cout<<"Aperte qualquer tecla para continuar";
                             go=getch();
                             goto aposento18;
                        }
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Voc""\x88"" entra no pequeno t""\xA3""nel e se depara com uma porta negra com 3 ";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"desenhos dourados e brilhantes. S""\xC6""o eles, uma lua, um sol e uma ";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"estrela. Os tr""\x88""s est""\xC6""o nas pontas de um triangulo.";
                        gotoxy(2,g);g++;delay(250);
                        cout<<"Esta porta est""\xA0"" trancada";
                        goto apos14b;
                   case 4:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta sul";
			            goto apos13b;
                   default:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        clrscr() ;menun(); g=2;
                        goto apos14bo;
              }
              //apos15b
         case 8:
              apos15b:{}
              clrscr() ;menun(); g=2;
	          gotoxy(20,g);g++;delay(250);
              cout<<" ***APOSENTO 15*** ";
              gotoxy(2,g);g++;delay(250);
              cout<<"Voc""\x88"" retorna ao aposento e ve ao ch""\xC6""o o cerberos que voc""\x88""";
              gotoxy(2,g);g++;delay(250);
              cout<<"matou e o aposento est""\xA0"" exatamente como estava quando";
              gotoxy(2,g);g++;delay(250);
              cout<<"voc""\x88"" passou pela ultima vez";
              gotoxy(2,22);g++;delay(250);
              cout<<"Aperte qualquer tecla para continuar";
              go=getch();
              clrscr() ;menun(); g=2;
              apos15bo:{}
              gotoxy(20,2);g++;delay(250);
              cout<<"***APOSENTO 15***";
	          gotoxy(2,g);g++;delay(250);
              cout<<"Qual porta deseja seguir?";
              gotoxy(2,g);g++;delay(250);
              cout<<"1. Sul";
              gotoxy(2,g);g++;delay(250);
              cout<<"2. Norte";
              gotoxy(2,g);g++;delay(250);
              cin>>op;
	          switch(op)
              {
                   case 1:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta sul";
                        goto apos14b;
                   case 2:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"Voc""\x88"" seguiu pela porta norte";
                        if(aposent16==1)
                        {
                             goto apos16b;
                        }
			            goto aposento16;
                   default:
                        gotoxy(2,18);g++;delay(250);
                        cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
                        clrscr() ;menun(); g=2;
			            goto apos15bo;
              }
	      //apos16b
	    case 9:
	      apos16b:{}
	      clrscr();
	      menun();
	      g=2;
	      gotoxy(20,g);g++;delay(250);
	      cout<<" ***APOSENTO 16*** ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"O aposento est""\xA0"" exatamente como estava quando voc""\x88"" passou";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"pela ultima vez";
	      gotoxy(2,22);g++;delay(250);
	      cout<<"Aperte qualquer tecla para continuar";
	      go=getch();
	      clrscr(); menun(); g=2;
          gotoxy(20,2);g++;delay(250);
          cout<<"***APOSENTO 16***";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Voc""\x88"" ve que n""\xC6""o h""\xA0"" mais nada a se fazer nesse aposento e ent""\xC6""o";
          gotoxy(2,g);g++;delay(250);
	      cout<<"resolve deixa-lo e voltar ao aposento anterior";
          gotoxy(2,22);g++;delay(250);
	      cout<<"Aperte qualquer tecla para continuar";
	      goto apos15b;
	      //apos17b
	   case 10:
	      apos17b:{}
	      clrscr();
	      menun();
	      g=2;
	      gotoxy(20,g);g++;delay(250);
	      cout<<" ***APOSENTO 17*** ";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"O aposento est""\xA0"" exatamente como estava quando voc""\x88"" passou";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"pela ultima vez";
	      gotoxy(2,22);g++;delay(250);
	      cout<<"Aperte qualquer tecla para continuar";
	      go=getch();
	      clrscr() ;menun(); g=2;
          gotoxy(20,2);g++;delay(250);
          cout<<"***APOSENTO 17***";
	      gotoxy(2,g);g++;delay(250);
	      cout<<"Voc""\x88"" encontra o rei Aranha morto no meio do aposento e voc""\x88""";
          gotoxy(2,g);g++;delay(250);
	      cout<<"ve que n""\xC6""o h""\xA0"" mais nada a se fazer ali e se retira";
          gotoxy(2,22);g++;delay(250);
	      cout<<"Aperte qualquer tecla para continuar";
          go=getch();
	      goto apos14b; }
     //fim das segundas passagens por aposentos////////////////////////////////
     //////////////////////////////////////////////////////////////////////////
     //em caso de morte acidental//////////////////////////////////////////////
     dead:   {
	      gotoxy(2,g);
	      cout<<"Voce se junta aos outros que tentaram pegar o tesouro";
	      goto end; }
     end:{
	      clrscr();
	      gotoxy(20,20);
	      cout<<"GAME OVER";
	      goto fim; }
     //aposento 18  ultimo/////////////////////////////////////////////////////
     aposento18:{}
     clrscr();
     menun();
     g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 18***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" entra no pequeno t""\xA3""nel e se depara com uma porta negra com 3 ";
     gotoxy(2,g);g++;delay(250);
     cout<<"desenhos dourados e brilhantes. S""\xC6""o eles, uma lua, um sol e uma ";
     gotoxy(2,g);g++;delay(250);
     cout<<"estrela. Os tr""\x88""s est""\xC6""o nas pontas de um triangulo.";
     gotoxy(2,g);g++;delay(250);
     cout<<"O que deseja fazer?";
     gotoxy(2,g);g++;delay(250);
     cout<<"1. Entrar no aposento.";
     gotoxy(2,g);g++;delay(250);
     cout<<"2. Voltar ao aposento anterior.";
     gotoxy(2,g);g++;delay(250);
     cin>>op;
     switch(op) {
	 case 1:
	 gotoxy(2,g);g++;delay(250);
	 cout<<"Quando a porta se abre voc""\x88"" ent""\xC6""o v""\x88"" que o aposento ""\x82"" pouco ";
	 gotoxy(2,g);g++;delay(250);
	 cout<<"maior que um arm""\xA0""rio. H""\xA0"" uma mesa ornamentada, com duas asas ";
	 gotoxy(2,g);g++;delay(250);
	 cout<<"esculpidas, no centro da parede oposta, e sobre ela se encontra";
	 gotoxy(2,g);g++;delay(250);
	 cout<<"uma arca de madeira. O posicionamento da arca ""\x82"" perfeito em ";
	 gotoxy(2,g);g++;delay(250);
	 cout<<"rela""\x87""""\xC6""o a escultura das asas na mesa, parece que as asas ";
	 gotoxy(2,g);g++;delay(250);
	 cout<<"pertencem realmente a arca.A arca de madeira ""\x82"" de uma tonalidade";
	 gotoxy(2,g);g++;delay(250);
	 cout<<"de vermelho e escuro e tem detalhes dourados de sua fechadura.";
     gotoxy(2,22);g++;delay(250);
	 cout<<"Aperte qualquer tecla para continuar";
     go=getch();
	 break;
	 case 2:
     gotoxy(2,g);g++;delay(250);
	 cout<<"Voc""\x88"" retorna ao aposento anterior";
	 goto apos14b;
     default:
     gotoxy(2,18);g++;delay(250);
     cout<<"N""\xC6""o existe essa op""\x87""""\xC6""o";
     gotoxy(2,22);g++;delay(250);
	 cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     clrscr();
     menun();
     g=2;
     goto aposento18; }
     clrscr();
     menun();
     g=2;
     gotoxy(20,2);g++;delay(250);
     cout<<"***APOSENTO 18***";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" pega a arca em suas m""\xC6""os, satisfeito por ter feito a jornada";
     gotoxy(2,g);g++;delay(250);
     cout<<"e a abre. Vendo as 48 moedas de ouro que la est""\xC6""o,voc""\x88"" come""\x87""a a";
     ouro=ouro+48;
     gotoxy(2,g);g++;delay(250);
     cout<<"preparar-se para o caminho de volta e mostrar ao mundo todo o";
     gotoxy(2,g);g++;delay(250);
     cout<<"seu valor e coragem.";
     gotoxy(2,g);g++;delay(250);
     cout<<"Quando de repente voc""\x88"" ve um portal branco a sua frente e por ";
     gotoxy(2,g);g++;delay(250);
     cout<<"entre ele voc""\x88"" pode ver uma paisagem de um po""\x87""o. Voc""\x88"" parece conhecer";
     gotoxy(2,g);g++;delay(250);
     cout<<"tal paisagem, at""\x82"" voc""\x88"" se dar conta que ""\x82"" o po""\x87""o pelo qual voc""\x88"" entrou!";
     gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" atravessa o porta e ele desaparece logo em seguida.";
     g++;gotoxy(2,g);g++;delay(250);
     cout<<"Voc""\x88"" conseguiu sair com uma quantia equivalente a "<<ouro<<" moedas";
     gotoxy(2,g);g++;delay(250);
     cout<<"de ouro";
     gotoxy(2,22);g++;delay(250);
	 cout<<"Aperte qualquer tecla para continuar";
     go=getch();
     goto fim;
     //fim do aposento 18//////////////////////////////////////////////////////
     fim:{}
     if(op==30)
     {goto gato;}
     clrscr();
     menun();
     gotoxy(2,g);g++;delay(250);
     cout<<"Fim do jogo.";
     gotoxy(2,g);g++;delay(250);
     cout<<"deseja ver o mapa do jogo?(s para sim)";
     go=getch();
     if(go=='s') {
         clrscr();
         menun();
         g=2;
         gotoxy(22,2);g++;delay(250);
         cout<<"*** MAPA ***";
         gotoxy(2,g);g++;
         cout<<"            ____";
         gotoxy(2,g);g++;
         cout<<"           |    |";
         gotoxy(2,g);g++;
         cout<<"  _________|_16_|";
         gotoxy(2,g);g++;
         cout<<" |    |    |    |";
         gotoxy(2,g);g++;
         cout<<" |_18_|_17_|_15_|";
         gotoxy(2,g);g++;
         cout<<" |              |                  ______";
         gotoxy(2,g);g++;
         cout<<" |_________14___| _______________ |      |";
         gotoxy(2,g);g++;
         cout<<"         |      ||               ||__6___| ______";
         gotoxy(2,g);g++;
         cout<<"         |_____13                ||      ||      |";
         gotoxy(2,g);g++;
         cout<<"                 |______8________||      ||      |";
         gotoxy(2,g);g++;
         cout<<"                 |               ||      ||      |";
         gotoxy(2,g);g++;
         cout<<"                 |                4       5      |";
         gotoxy(2,g);g++;
         cout<<"                 |______3________||______||______|";
         gotoxy(2,g);g++;
         cout<<"                       |   |";
         gotoxy(2,g);g++;
         cout<<"                       |   |";
         gotoxy(2,g);g++;
         cout<<"                      _|_2_|_";
         gotoxy(2,g);g++;
         cout<<"                     |       |";
         gotoxy(2,g);g++;
         cout<<"                     |   1   |";
         gotoxy(2,g);g++;
         cout<<"                     |_______|";
     }
     gotoxy(2,22);
     cout<<"Aperte qualquer tecla para terminar o programa";
     go=getch();
     fimmesmo:{}
     clrscr();
     gotoxy(1,1);
     return 0;
}

