#include <stdio.h>
#include <stdlib.h>
#include <time.h> //((int)sizeof(cells)/(sizeof(cells[0][0])*8)) // *number of cols
#include "csvparser.c"
void sortthearray(float *ar,int thesize,int *sorind)
{
    float tempelement;
    int tempindex;
    int tempindexes[thesize];
    float temparray[thesize];
    for(int j=0;j<thesize;j++){
        for (int i=0;i<thesize-1;i++){
            if (*(ar+i)>*(ar+i+1)){
                tempelement=*(ar+i);
                tempindex=*(sorind+i);
                *(sorind+i)=*(sorind+i+1);
                *(sorind+i+1)=tempindex;
                *(ar+i)=*(ar+i+1);
                *(ar+i+1)=tempelement;
            }
        }
    }
    for (int i=0;i<thesize;i++){
            temparray[thesize-1-i]=*(ar+i);
            tempindexes[thesize-1-i]=*(sorind+i);

    }
    for (int i=0;i<thesize;i++){
            *(ar+i)=temparray[i];
            *(sorind+i)=tempindexes[i];
    }

}


int negornot(int n)
{
    int tempne=0;
    if(n==0){
        return 1;
    }
    else{
        tempne=rand()%2;
        if (tempne==1){
            return -1;
        }
        else{
            return 1;
    }
}
}
void intparameters(int min,int max,int coef,int negativity,int* x, int* y)
{
        int tempnegativity;
        tempnegativity=negornot(negativity);
        *x=((rand()%(max*(int)(1/coef)-min*(int)(1/coef)+1))+min*(1/coef))*coef*tempnegativity;
        tempnegativity=negornot(negativity);
        *y=((rand()%(max*(int)(1/coef)-min*(int)(1/coef)+1))+min*(1/coef))*coef*tempnegativity;
        while (*y<*x){
        tempnegativity=negornot(negativity);
            *y=((rand()%(max*(int)(1/coef)-min*(int)(1/coef)+1))+min*(1/coef))*coef*tempnegativity;
        }
}
void floatparameters(int min,int max,float coef,int negativity,float* x, float* y)
{
        int tempnegativity;
        tempnegativity=negornot(negativity);
        *x=((rand()%(max*(int)(1/coef)-min*(int)(1/coef)+1))+min*(1/coef))*coef*tempnegativity;
        tempnegativity=negornot(negativity);
        *y=((rand()%(max*(int)(1/coef)-min*(int)(1/coef)+1))+min*(1/coef))*coef*tempnegativity;
        while (*y<*x){
        tempnegativity=negornot(negativity);
            *y=((rand()%(max*(int)(1/coef)-min*(int)(1/coef)+1))+min*(1/coef))*coef*tempnegativity;
        }
}
int main(void) {
    //initialize random motor by srand
    srand((unsigned)(time(NULL)));
    int SIZE;
    printf("\nEnter the number of cells:");
    scanf("%d",&SIZE);
    int numberofchildperselected=5,numberofparents;
    float biggestwinratio=0;
    float biggestprize=0;
    float biggestfactor=0;
    int generation=0;
    int temprepro=0,temprepro2=0,tempinx=0,tempinx1=0,tempinx2=0;
    //create cells********************************************************************************************:
    int (*indexes)  = malloc(SIZE * sizeof *indexes),(*aliveordead)  = malloc(SIZE * sizeof *aliveordead),(*sortedindexes)  = malloc(SIZE * sizeof *sortedindexes),(*choosenindexes)  = malloc(SIZE * sizeof *choosenindexes);
    float (*fitness)  = malloc(SIZE * sizeof *fitness),(*sortedfitness)  = malloc(SIZE * sizeof *sortedfitness);
    //1 cumulative sum of profits, total prize//2number of positive profit/3controll number if bought or sold//4number of negative profit;//5profitable activity ratio//6number of sell activity//7buyprice//8sell ratio
    float (*cellinfo1)  = malloc(SIZE * sizeof *cellinfo1), (*cellinfo2) = malloc(SIZE * sizeof *cellinfo2),(*cellinfo3)  = malloc(SIZE * sizeof *cellinfo3),(*cellinfo5)  = malloc(SIZE * sizeof *cellinfo5),(*cellinfo6) = malloc(SIZE * sizeof *cellinfo6),(*cellinfo7)  = malloc(SIZE * sizeof *cellinfo7),(*cellinfo8)  = malloc(SIZE * sizeof *cellinfo8);
    printf("\nnumber of cells calculated= %d\n",SIZE);
    int (*cellinfo4) = malloc(SIZE * sizeof *cellinfo4);
    int (*par1) = malloc(SIZE * sizeof *par1),(*par2)  = malloc(SIZE * sizeof *par2),(*par3) = malloc(SIZE * sizeof *par3),(*par4) = malloc(SIZE * sizeof *par4)\
    ,(*par5)  = malloc(SIZE * sizeof *par5),(*par6)  = malloc(SIZE * sizeof *par6),(*par7)  = malloc(SIZE * sizeof *par7),(*par8) = malloc(SIZE * sizeof *par8);  //for each input 8 parameters as = 2 b trigger , 2b ,2s trigger ,2s
    //decimal ratio parameters must be float like rate of change
    float(*par9) = malloc(SIZE * sizeof *par9),(*par10) = malloc(SIZE * sizeof *par10),(*par11) = malloc(SIZE * sizeof *par11),(*par12) = malloc(SIZE * sizeof *par12),(*par13) = malloc(SIZE * sizeof *par13),(*par14) = malloc(SIZE * sizeof *par14),(*par15) = malloc(SIZE * sizeof *par15),(*par16) = malloc(SIZE * sizeof *par16);
    float (*par17) = malloc(SIZE * sizeof *par17),(*par18) = malloc(SIZE * sizeof *par18),(*par19) = malloc(SIZE * sizeof *par19),(*par20) = malloc(SIZE * sizeof *par20),(*par21) = malloc(SIZE * sizeof *par21),(*par22) = malloc(SIZE * sizeof *par22),(*par23) = malloc(SIZE * sizeof *par23),(*par24) = malloc(SIZE * sizeof *par24);
    int tempneg;    float temp1=0;    float temp2=0;    float temp3=0;
    float close;
    float rsivalue;
    float roc1value;
    float roc2value;
    while (1){
    printf("\n\nrsiroc5===GEN %d===Biggest win ratio is %f and biggest prize is %f\n",generation,biggestwinratio,biggestprize);
        generation++;
    // ============================= file, delimiter, first_line_is_header?==============================
    CsvParser *data = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\data180d3m.csv", ",", 0);
    //create a second shadow to get the row number
    CsvParser *data2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\data180d3m.csv", ",", 0);
    //create class  for indicator csvs ------------------------------
    CsvParser *rsi = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180drsi3m.csv", ",", 0);
    CsvParser *roc1 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180droc13m.csv", ",", 0);
    CsvParser *roc2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180droc23m.csv", ",", 0);
    //create rows for data file :
    CsvRow *row;
    //to get the  row number create a rows from second, from the shadow
    CsvRow *row2;
    ////create rows for data2 file :to get the number of elements in the row get the first row
    row2 = CsvParser_getRow(data2);
    //find the number of fields in the row with row2->numofFields_
    printf("\nNumber of elements inside the row=%d \n",row2->numOfFields_);
    //for table length= number of rows=
    int numofrows=0;
    while ((row2 = CsvParser_getRow(data2)) ) {
    	numofrows++;
        CsvParser_destroy_row(row2);
    }
    //create rows  for indicator csvs
    CsvRow *rsirows;
    CsvRow *roc1rows;
    CsvRow *roc2rows;
    //print the number of rows:-------------------------
    printf("Number of rows=%d \n",numofrows);
    //["Open_time", "Open", "High", "Low", "Close", "Volume", "Close_time", "qav", "noot", "tbbav","tbqav", "ignore"]
    //follow row number "attherow"
    int attherow=0;
    //field names in the rows for candle stick data
    char thename[][15]={"Open_time", "Open", "High", "Low", "Close", "Volume", "Close_time", "qav", "noot", "tbbav","tbqav", "ignore"};
 //assign random min max parameters
    for (int i=0;i<SIZE;i++){
        indexes[i]=i; choosenindexes[i]=0;
        cellinfo1[i]=0; cellinfo6[i]=0; cellinfo2[i]=0; cellinfo3[i]=0;cellinfo7[i]=1;
        if (aliveordead[i]!=1){
            intparameters(0,100,1,0,&par1[i],&par2[i]);
            intparameters(0,100,1,0,&par3[i],&par4[i]);
            intparameters(0,100,1,0,&par5[i],&par6[i]);
            intparameters(0,100,1,0,&par7[i],&par8[i]);
            //******NEGATIVE DECIMAL PARAMETERS******************
            floatparameters(0,10,0.01,1,&par9[i],&par10[i]);
            floatparameters(0,10,0.01,1,&par11[i],&par12[i]);
            floatparameters(0,10,0.01,1,&par13[i],&par14[i]);
            floatparameters(0,10,0.01,1,&par15[i],&par16[i]);

            floatparameters(0,100,0.01,1,&par17[i],&par18[i]);
            floatparameters(0,100,0.01,1,&par19[i],&par20[i]);
            floatparameters(0,100,0.01,1,&par21[i],&par22[i]);
            floatparameters(0,100,0.01,1,&par23[i],&par24[i]);
            }
        //printf("\n %f   %f\n",par9[i],par10[i]);
        aliveordead[i]=0;
    }
    sortedindexes=indexes;
    printf("\n Cells produced %d \n",SIZE);
    //pass the data row by row then destroy the row
    while ((row = CsvParser_getRow(data)) ) {
    	//printf("\n==%d LINE==\n",++attherow); // ********indicator row call*****
    	rsirows=CsvParser_getRow(rsi);
    	roc1rows=CsvParser_getRow(roc1);
    	roc2rows=CsvParser_getRow(roc2);

    	//*************data row ***************  standart input row as open,close etc.
        const char **rowFields = CsvParser_getFields(row);
        //value array, values in the row for **** indicator******
        const char **rsirowvalue = CsvParser_getFields(rsirows);
        const char **roc1rowvalue = CsvParser_getFields(roc1rows);
        const char **roc2rowvalue = CsvParser_getFields(roc2rows);
        //*****data value****** string to float %f  strtod(inp,NULL) close price, str to double strtod
        close = strtod(rowFields[4], NULL);
        //pass through row fields in ****data columns**** close=4:
        for (int i = 4; i < 5 ; i++) {   //(int i = 0 ; i < CsvParser_getNumFields(row) ; i++)
        //printf("--------------------%s %d: %s--------------------\n", thename[i],i,rowFields[i]);
        }
        //string to float %f  strtod(inp,NULL)    rsi value     **** indicator ****
        rsivalue = strtod(rsirowvalue[0], NULL);
        roc1value = strtod(roc1rowvalue[0], NULL);
        roc2value = strtod(roc2rowvalue[0], NULL);
        //pass through cells
        for (int i=0;i<SIZE;i++){
        //  ---------------------------------------bot area----------------------------------------------------------------------------
        if ((cellinfo3[i]==0)&&(par1[i]<rsivalue) && (rsivalue<par2[i])&& (par9[i]<roc1value) && (roc1value<par10[i])&& (par17[i]<roc2value) && (roc2value<par18[i])){ //***BUY trigger*******
        cellinfo3[i]=0.5;
        }
        else if ((cellinfo3[i]==0.5)&&(par3[i]<rsivalue) && (rsivalue<par4[i])&& (par11[i]<roc1value) && (roc1value<par12[i])&& (par19[i]<roc2value) && (roc2value<par20[i])){         //***********BUY************
            cellinfo3[i]=1;
            cellinfo7[i]=close;
        }
        else if ((cellinfo3[i]==1)&&(par5[i]<rsivalue) && (rsivalue<par6[i])&& (par13[i]<roc1value) && (roc1value<par14[i])&& (par21[i]<roc2value) && (roc2value<par22[i])){         //***********SELL trigger************
        cellinfo3[i]=0.75;
        }
        else if ((cellinfo3[i]==0.75)&&(par7[i]<rsivalue) && (rsivalue<par8[i])&& (par15[i]<roc1value) && (roc1value<par16[i])&& (par23[i]<roc2value) && (roc2value<par24[i])){         //***********SELL************
        cellinfo3[i]=0;
        cellinfo6[i]++;
        cellinfo8[i]=close/ cellinfo7[i];
        cellinfo1[i]+=cellinfo8[i]-1;
        if ((cellinfo8[i]-1)>0.004){
            cellinfo2[i]++;
        }
        }
        } //----------------------------------------------------------------------------------------------------------------------
        CsvParser_destroy_row(row);
        CsvParser_destroy_row(rsirows);
        CsvParser_destroy_row(roc1rows);
        CsvParser_destroy_row(roc2rows);
    }
    temp1=0;
    temp2=0;
    temp3=0;
    //*******************************************************determines the fitness here *******************************
    for (int i=0;i<SIZE;i++){
            if ((cellinfo6[i]>0.3)){ //ZERO DIVISION ERROR OLMAMASI ICIN cellinfo6 MUTLAKA 0DAN BUYUK OLMALI DE��LSE FITNESS=0 yap diyor bu if
                temp1=(cellinfo2[i]*1.0)/cellinfo6[i]; //win ratio
            }
            else{
                temp1=0;
            }
            temp2=cellinfo1[i]; // total prize
            temp3=(temp1+temp2/10.0)*10000*(temp2/(cellinfo6[i]))*((cellinfo6[i]*3/(numofrows*1.0)));  //cellinfo6/numofrows= willingness to make a move
            fitness[i]=temp3;
            if ((temp1>0.3)&& ((cellinfo6[i]/(numofrows*1.0)>0.001))){       //winrate >%30 ->
            if ((biggestfactor<temp3)){
                biggestwinratio=temp1;
                biggestprize=temp2;
                biggestfactor=temp3;
                printf("\n---\n%d.cell parameters are= %d RSIbuytrigger %d | %f ROCbuytrigger %f | %d rsibuy %d | %f ROCbuytrigger %f \n %d rsiselltrigger %d | %f ROCselltrigger %f| %d rsisell %d | %f ROCsell %f \nWinratio: %f , number of sell activity= %f , movement ratio= %f ,prize= %f , temp3=%f"\
                   ,i,par1[i],par2[i],par9[i],par10[i],par3[i],par4[i],par11[i],par12[i],par5[i],par6[i],par13[i],par14[i],par7[i],par8[i],par15[i],par16[i],temp1,cellinfo6[i],(cellinfo6[i]/(numofrows*1.0)),temp2,temp3);
            }
        }
    }
    sortedfitness=fitness;
    sortthearray(sortedfitness,SIZE,sortedindexes);
    printf("\nSorted\n");
    //*************************************CHOOSE BEST CELLS*****************************
    temprepro=0;
    for (int i=0;i<(SIZE/30);i++){
            if ((sortedfitness[i]>0)){
                aliveordead[sortedindexes[i]]=1;
                choosenindexes[temprepro]=sortedindexes[i];
                if (sortedindexes[i]==0){
                    choosenindexes[temprepro]=-1;
                }
                temprepro++;
            }
    }
    numberofparents=temprepro;
    printf("\nNumber of parents=%d",temprepro);
    //********************************CREATE NEW CELLS************************ multi-point uniform crossover
    temprepro=0;
    temprepro2=0;
    while(choosenindexes[temprepro]!=0){
            if (choosenindexes[temprepro]==-1){
                choosenindexes[temprepro]=0;
            }
            else if     (choosenindexes[temprepro]==0){
                break;
            }
            for (int i=0;i<numberofchildperselected;i++){
                tempinx=SIZE-1-temprepro2;
                aliveordead[tempinx]=1;     //sondan baslayarak olu hucreleri canland�r�yor boylece bunu yavruya donustureceg�m
                //List of parameters
                tempneg=rand()%(numberofparents+1);
                par1[tempinx]=par1[choosenindexes[tempneg]];
                par2[tempinx]=par2[choosenindexes[tempneg]];
                //--------
                tempneg=rand()%(numberofparents+1);
                par3[tempinx]=par3[choosenindexes[tempneg]];
                par4[tempinx]=par4[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par5[tempinx]=par5[choosenindexes[tempneg]];
                par6[tempinx]=par6[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par7[tempinx]=par7[choosenindexes[tempneg]];
                par8[tempinx]=par8[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par9[tempinx]=par9[choosenindexes[tempneg]];
                par10[tempinx]=par10[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par11[tempinx]=par11[choosenindexes[tempneg]];
                par12[tempinx]=par12[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par13[tempinx]=par13[choosenindexes[tempneg]];
                par14[tempinx]=par14[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par15[tempinx]=par15[choosenindexes[tempneg]];
                par16[tempinx]=par16[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par17[tempinx]=par17[choosenindexes[tempneg]];
                par18[tempinx]=par18[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par19[tempinx]=par19[choosenindexes[tempneg]];
                par20[tempinx]=par20[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par21[tempinx]=par21[choosenindexes[tempneg]];
                par22[tempinx]=par22[choosenindexes[tempneg]];
                //------------
                tempneg=rand()%(numberofparents+1);
                par23[tempinx]=par23[choosenindexes[tempneg]];
                par24[tempinx]=par24[choosenindexes[tempneg]];
                //------------
                temprepro2++;
            }
            temprepro++;
    }
    printf("\nNew generation with %d members has reproduced!",temprepro2);
    CsvParser_destroy(data);
    CsvParser_destroy(data2);
    CsvParser_destroy(rsi);
    CsvParser_destroy(roc1);
    CsvParser_destroy(roc2);
    }

    printf("\nEnter any key to terminate");
    scanf("\n%f",&close);
    return 0;
}
