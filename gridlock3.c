/*
        ########
     ##############
   #####        #####
  ####            ####
 ####              ####
 ###                ###
####                ####
####                ####
                    ####
                    ####
                    ####
                    ####
*/

            main(int
         c,char**v){int
       ETE=-        0,DEL
      =010            ,ME,
     s;ME              =ETE
     --;                DEL
    =ETE                ?~0:
    DEL%                8;s=
                        DEL|
                        ETE|
                        ~ME|
#define U(c)(c&&c-1>>6&(c)/13<0x7)
1;/*if(c^3)return!!printf("Usage: %"
"s key text\n",*v);char*k=*++v,*t,
a,j,d=32;for(c=0  ;k[c];c++);for(t
=k;*t;t++){if(      U(*t-d))*t-=d;
if(!U(*t))return  !!puts("Key mus"
"t be letters");  }t=**v;for(j=0;*
t;t++){a=U(*t)?    65:U(*t-d)*97;a
&&(*t=a+((*t-a      )+s*(k[j++%c]-'A')+26)%26);
*/

/***************  ***************/
/************(      7************/
/**************    **************/
/***************  ***************/
/**************    **************/
/*************      *************/
/********************************/
/********************************/
s=1;
/* 32 * 10 */

/* could obfuscate this string if there's room */
/*if(c^3)return!!printf("Usage: %s key text\n",*v);*/
if(c^3)return!f(1);

char*k=*++v,*t,a;
for(c=0;k[c];c++);

for(t=k;*t;t++){
if(U(*t-32))*t-=32;
/*if(!U(*t))return!!puts("Key must be letters");*/
if(!U(*t))return!f(0);
}

t=*++v;
int j=0;
for(;*t;t++){
/*a=*t>64&*t<91?'A':*t>96&*t<'{'?'a':0;*/
a=U(*t)?'A':U(*t-32)?'a':0;
a&&(*t=a+((*t-a)+s*(k[j++%c]-'A')+26)%26);
}

return!puts(*v);}

f(x){
char*s="R5k5~l$vplwftmto\037b`ib\x1d\x1cgg`_sm\x19ll\\\\hnhi\0";
s+=x;
for(x=-7;*s;s+=2) {
putchar(x+++*s);
}
return!putchar(10);
}

	/*
	s = "Rk~$pwtt\x1f`b\x1cg_ml\\hh";
	s = "55lvlfmobi\x1dg`s\x19l\\ni";
	*/

/*
for(s=0;s<127;s++) {
	printf("%d\t%d\n", s, U(s));
}
return 0;
*/
/*
#define F(i)for(;*z;z++)putchar(i+*z);
char *z = "Mionp!\t";
int i = -5;
F(i++)
z=*v;F(0)
*/
