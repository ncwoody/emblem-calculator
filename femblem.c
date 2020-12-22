#include <stdio.h>

// initializing the functions we will need
int calspeed( int speed, int weight, int con );
int calrepeat( int speed1, int speed2 );
int calrate( int acc, int skill, int luck, int support, int rank );
int calavoid( int speed, int luck, int terrain, int support );
int calacc( int rate, int evade, int triangle );
int calattack( int atk, int might, int triangle, int eff, int support );  // use this for physical and magical
int caldefense( int def, int terrain, int support );  // can use this for resistance too
int caldamage( int atk, int def );
int calcrit( int dmg );
int calrate( int weapon, int skill, int support, int class, int rank );
int calevade( int luck, int support );
int calchance( int rate, int evade );
void printresults( int rep, int acc1, int dmg1, int crit1, int chance1, int acc2, int dmg2, int crit2, int chance2 );

int main()
{
	// all the variables we will need- 1 is for attacker, 2 is for defender
	int speed1;  // for calculating speed
	int weight1;  // for calculating speed
	int con1;  // for calculating speeed
	int speed2;  // for calculating speed, avoid
	int weight2;  // for calcuating speed
	int con2;  // for calculating speed
	int calcspd1;  // the calculated speed for attacker
	int calcspd2;  // the calculated speed for defender
	int calcrep;  // if there is a repeated attack or not
	int acc1;  // for calculating hit rate
	int acc2;  // accuracy of defender
	int skill1;  // for calculating hit rate
	int skill2;  // skill of defender
	int luck1;  // for calculating hit rate
	int support1;  // for calculating hit rate
	int srank1;  // for calculating hit rate- is +5 to hit rate
	int srank2;  // srank of defender
	int calcrate;  // the calculated hit rate
	int luck2;  // for calculating avoid
	int terrain1;  // for calculating avoid for attacker
	int terrain2;  // for calculating avoid
	int support2;  // for calculating avoid;
	int calcavoid; // the calculated avoid rate
	int triangle;  // for calculating accuracy
	int calcacc1;  // the calculated accuracy of the attacker
	int calcacc2;  // the calculated accuracy of the defender
	int type1;  // for calculating the attacker's damage
	int type2;  // for calculating the defender's damage
	int str1;  // for calculating the attacker's damage
	int str2;  // for calculating the defender's damage
	int mag1;  // same as above
	int mag2;  // same as above
	int might1;  // for calculating the attacker's damage
	int might2;  // for calculating the defender's damage
	int eff1;  // for calculating the attacker's damage
	int eff2;  // for calculating the defender's damage
	int def1;  // for calculating the damage to be delt
	int def2;  // for calculating the damage to be delt
	int res1;  // for calculating the damage to be delt
	int res2;  // for calculating the damage to be delt
	int calcatt1;  // for holding the damage the attacker does
	int calcatt2;  // for holding the damage the defender does
	int calcdef1;  // for holding the defense value
	int calcdef2;  // for holding the defense value
	int calcdamage1;  // how much damage the attacker does
	int calcdamage2;  // how much damage the defender does
	int calccritdmg1;  // how much damage the attacker's crit will do
	int calccritdmg2;  // how much damage the defender's crit will do
	int crit1;  // for calculating crit rate
	int crit2;  // for calculating crit rate
	int class1;  // for calculating crit rate
	int class2;  // for calculating crit rate
	int calcrate1;  // crit rate for attacker
	int calcrate2;  // crit rate for defender
	int calcevade1;  // crit evade for attacker
	int calcevade2;  // crit evade for defender
	int calcchance1;  // crit chance for attacker
	int calcchance2;  // crit chance for defender
	
	// calculating if one participant doubles the other
	printf("What is the speed of the attacker?");
	scanf("%d", &speed1);
	printf("What is the weight of the attacker?");
	scanf("%d", &weight1);
	printf("What is the constitution of the attacker?");
	scanf("%d", &con1);
	printf("What is the speed of the defender?");
	scanf("%d", &speed2);
	printf("What is the weight of the defender?");
	scanf("%d", &weight2);
	printf("What is the constitution of the defender?");
	scanf("%d", &con2);
	calcspd1 = calspeed( speed1, weight1, con1 );
	calcspd2 = calspeed( speed2, weight2, con2 );
	calcrep = calrepeat( calcspd1, calcspd2 );
	if ( calcrep == 1 )
		printf("The attacker will attack twice\n");
	else if ( calcrep == -1 )
		printf("The defender will attack twice\n");
	else if ( calcrep == 0 )
		printf("Both the attacker and the defender will attack only once\n");
	
	// calculating how likely the attack is to hit
	printf("What is the accuracy of the attacker's weapon?");
	scanf("%d", &acc1);
	printf("What is the attacker's skill?");
	scanf("%d", &skill1);
	printf("What is the attacker's luck?");
	scanf("%d", &luck1);
	printf("What is the attacker's support bonus?");
	scanf("%d", &support1);
	printf("Does the attacker have an S-rank bonus? (1 for yes and 0 for no)");
	scanf("%d", &srank1);
	printf("What is the terrain bonus that the attacker gets?");
	scanf("%d", &terrain1);
	printf("What is the defender's luck?");
	scanf("%d", &luck2);
	printf("What is the terrain bonus the defender gets?");
	scanf("%d", &terrain2);
	printf("What is the defender's support bonus?");
	scanf("%d", &support2);
	printf("What is the accuracy of the defender's weapon?");
	scanf("%d", &acc2);
	printf("What is the defender's skill?");
	scanf("%d", &skill2);
	printf("Does the defender have an S-rank bonus? (1 for yes and 0 for no)");
	scanf("%d", &srank2);
	printf("Is there a weapon triangle advantage? (1 for attacker, 2 for defender, 0 for neither)");
	scanf("%d", &triangle);
	calcrate = calrate( acc1, skill1, luck1, support1, srank1 );
	calcavoid = calavoid( calcspd2, luck2, terrain2, support2 );
	calcacc1 = calacc( calcrate, calcavoid, triangle );
	printf("The accuracy of the attacker's attack is: %d\n", calcacc1);
	calcrate = calrate( acc2, skill2, luck2, support2, srank2 );
	calcavoid = calavoid( calcspd1, luck1, terrain1, support1 );
	calcacc2 = calacc( calcrate, calcavoid, triangle );
	printf("The accuracy of the defender's attack is: %d\n", calcacc2);
	
	// calculating how much damage the attack will do
	printf("Is the attacker attacking with a physical or magical weapon? (1 for physical and 0 for magical)");
	scanf("%d", &type1);
	if ( type1 == 1 )  // physical attack
	{
		printf("What is the attacker's strength?");
		scanf("%d", &str1);
		printf("What is the might of the attacker's weapon?");
		scanf("%d", &might1);
		printf("Is the attacker's weapon effective against the defender? (1 for yes and 0 for no)");
		scanf("%d", &eff1);
		printf("What is the defender's defense stat?");
		scanf("%d", &def2);
		calcatt1 = calattack( str1, might1, triangle, eff1, support1 );
		calcdef2 = caldefense( def2, terrain2, support2 );
	}
	else if ( type1 == 0 )  // magical attack
	{
		printf("What is the attacker's magic?");
		scanf("%d", &mag1);
		printf("What is the might of the attacker's weapon?");
		scanf("%d", &might1);
		printf("Is the attacker's weapon effective agains the defender? (1 for yes and 0 for no)");
		scanf("%d", &eff1);
		printf("What is the defender's resistance stat?");
		scanf("%d", &res2);
		calcatt1 = calattack( mag1, might1, triangle, eff1, support1 );
		calcdef2 = caldefense( def2, terrain2, support2 );
	}
	printf("Is the defender attacking with a physical or magical weapon? (1 for physical and 0 for magical)");
	scanf("%d", &type2);
	if ( type1 == 1 )  // physical attack
	{
		printf("What is the defender's strength?");
		scanf("%d", &str2);
		printf("What is the might of the defender's weapon?");
		scanf("%d", &might2);
		printf("Is the defender's weapon effective against the attacker? (1 for yes and 0 for no)");
		scanf("%d", &eff2);
		printf("What is the attacker's defense stat?");
		scanf("%d", &def1);
		calcatt2 = calattack( str2, might2, triangle, eff2, support2 );
		calcdef2 = caldefense( def1, terrain1, support1 );
	}
	else if ( type2 == 0 )  // magical attack
	{
		printf("What is the defender's magic?");
		scanf("%d", &mag2);
		printf("What is the might of the defender's weapon?");
		scanf("%d", &might2);
		printf("Is the defender's weapon effective agains the attacker? (1 for yes and 0 for no)");
		scanf("%d", &eff2);
		printf("What is the attacker's resistance stat?");
		scanf("%d", &res1);
		calcatt2 = calattack( mag2, might2, triangle, eff2, support2 );
		calcdef2 = caldefense( res1, terrain1, support1 );
	}
	calcdamage1 = caldamage( calcatt1, calcdef2 );
	calcdamage2 = caldamage( calcatt2, calcdef2 );
	printf("The attacker will do %d damage\n", calcdamage1);
	printf("The defender will do %d damage\n", calcdamage2);
	
	// calculating crit stats
	calccritdmg1 = calcrit( calcdamage1 );
	calccritdmg2 = calcrit( calcdamage2 );
	printf("What is the attacker's weapon's critical rate?");
	scanf("%d", &crit1);
	printf("What is the class bonus to critical for the attacker's class?");
	scanf("%d", &class1);
	printf("What is the defender's weapon's critical rate?");
	scanf("%d", &crit2);
	printf("What is the class donus to critical for the defender's calss?");
	scanf("%d", &class2);
	calcrate1 = calrate( crit1, skill1, support1, class1, srank1 );
	calcevade1 = calevade( luck2, support2 );
	calcchance1 = calchance( calcrate1, calcevade1 );
	calcrate2 = calrate( crit2, skill2, support2, class2, srank2 );
	calcevade2 = calevade( luck1, support1 );
	calcchance2 = calchance( calcrate2, calcevade2 );
	printf("The attacker has a %d percent chance to crit, and will do %d damage if they crit\n", calcchance1, calccritdmg1 ); 
	printf("The defender has a %d percent chance to crit, and will do %d damage if they crit\n", calcchance2, calccritdmg2 );
	
	
	printresults( calcrep, calcacc1, calcdamage1, calccritdmg1, calcchance1, calcacc2, calcdamage2, calccritdmg2, calcchance2 );
	return 0;
}

int calspeed( int speed, int weight, int con )
{
	int ret;
	
	if ( weight <= con )
	{
		return speed;
	}
	else 
	{
		weight = weight - con;
		ret = speed - weight;
		return ret;
	}
}

int calrepeat( int speed1, int speed2 )
{
	if ( speed1 >= speed2 + 4 )
		return 1;
	else if ( speed2 >= speed1 + 4 )
		return -1;
	else
		return 0;
}

int calrate( int acc, int skill, int luck, int support, int rank )
{
	int ret;
	
	skill = ( skill * 2 );
	luck = ( luck / 2 );
	if ( rank == 1 )  // has s-rank in weapon
		rank = 5;
	ret = ( acc + skill + luck + support + rank );
	
	return ret;
}

int calavoid( int speed, int luck, int terrain, int support )
{
	int ret;
	
	speed = ( speed * 2 );
	ret = ( speed + luck + terrain + support );
	
	return ret;
}

int calacc( int rate, int evade, int triangle )
{
	int ret;
	int acc;
	
	if ( triangle == 1 )  // attacker has advantage
		acc = 15;
	else if ( triangle == 2 )  // defender has advantage
		acc = -15;
	else if ( triangle == 0 )  // neither has advantage
		acc = 0;
		
	ret = ( rate - evade + acc );
	return ret;
}

int calattack( int atk, int might, int triangle, int eff, int support )
{
	int ret;
	int temp;
	int dmg;
	
	if ( triangle == 1 )  // attacker has advantage
		dmg = 1;
	else if ( triangle == 2 )  // defender had advantage
		dmg = -1;
	else if ( triangle == 0 )  // neither has advantage
		dmg = 0;
		
	if ( eff == 1 )  // weapon is effective
		eff = 3;
	else if ( eff == 0 )  // weapon is not effective
		eff = 1;
	
	temp = ( might + dmg );
	temp = ( atk + temp );
	temp = ( temp * eff );
	ret = ( temp + support );
	return ret;
}

int caldefense( int def, int terrain, int support )
{
	int ret;
	ret = ( terrain + def + support );
	return ret;
}

int caldamage( int atk, int def )
{
	int ret;
	ret = ( atk - def );
	return ret;
}

int calcrit( int dmg )
{
	int ret;
	ret = ( dmg * 3 );
	return ret;
}

int calcritrate( int weapon, int skill, int support, int class, int rank )
{
	int ret;
	
	skill = ( skill / 2 );
	ret = ( weapon + skill + support + class + rank );
	
	return ret;
}

int calevade( int luck, int support )
{
	int ret;
	ret = ( luck + support );
	return ret;
}

int calchance( int rate, int evade )
{
	int ret;
	ret = ( rate - evade );
	return ret;
}

void printresults( int rep, int acc1, int dmg1, int crit1, int chance1, int acc2, int dmg2, int crit2, int chance2 )
{
	printf("\n\n----------------------------------------------------------------------------------------------------------------\n");
	printf("The final results:\n\n");
	
	printf("Attacker:\n");
	if ( rep == 1 )
		printf("Will attack twice\n");
	printf("Will have an attack hit chance of %d\n", acc1);
	printf("Will do %d damage if they hit, and %d damage if they crit\n", dmg1, crit1);
	printf("Their crit chance is %d\n\n", chance1);
	
	printf("Defender:\n");
	if ( rep == -1 )
		printf("Will attack twice\n");
	printf("Will have an attack hit chance of %d\n", acc2);
	printf("Will do %d damage if they hit, and %d damage if they crit\n", dmg2, crit2);
	printf("Their crit chance is %d\n\n", chance2);
	
	printf("----------------------------------------------------------------------------------------------------------------\n");
}