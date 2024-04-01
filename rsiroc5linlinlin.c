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
    int tempne;
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
        *x=((rand()%(max-min+1))+min)*coef*tempnegativity;
        tempnegativity=negornot(negativity);
        *y=((rand()%(max-min+1))+min)*coef*tempnegativity;
        while (*y<*x){
        tempnegativity=negornot(negativity);
            *y=((rand()%(max-min+1))+min)*coef*tempnegativity;
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
    int temprepro=0,temprepro2=0,temprepro3=0,tempinx=0,tempinx1=0,tempinx2=0;
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
    float (*par25) = malloc(SIZE * sizeof *par25),(*par26) = malloc(SIZE * sizeof *par26),(*par27) = malloc(SIZE * sizeof *par27),(*par28) = malloc(SIZE * sizeof *par28),(*par29) = malloc(SIZE * sizeof *par29),(*par30) = malloc(SIZE * sizeof *par30),(*par31) = malloc(SIZE * sizeof *par31),(*par32) = malloc(SIZE * sizeof *par32),(*par33) = malloc(SIZE * sizeof *par33),(*par34) = malloc(SIZE * sizeof *par34),(*par35) = malloc(SIZE * sizeof *par35),(*par36) = malloc(SIZE * sizeof *par36),(*par37) = malloc(SIZE * sizeof *par37),(*par38) = malloc(SIZE * sizeof *par38),(*par39) = malloc(SIZE * sizeof *par39),(*par40) = malloc(SIZE * sizeof *par40),(*par41) = malloc(SIZE * sizeof *par41),(*par42) = malloc(SIZE * sizeof *par42),(*par43) = malloc(SIZE * sizeof *par43),(*par44) = malloc(SIZE * sizeof *par44),(*par45) = malloc(SIZE * sizeof *par45),(*par46) = malloc(SIZE * sizeof *par46),(*par47) = malloc(SIZE * sizeof *par47),(*par48) = malloc(SIZE * sizeof *par48),(*par49) = malloc(SIZE * sizeof *par49),(*par50) = malloc(SIZE * sizeof *par50),(*par51) = malloc(SIZE * sizeof *par51),(*par52) = malloc(SIZE * sizeof *par52),(*par53) = malloc(SIZE * sizeof *par53),(*par54) = malloc(SIZE * sizeof *par54),(*par55) = malloc(SIZE * sizeof *par55),(*par56) = malloc(SIZE * sizeof *par56),(*par57) = malloc(SIZE * sizeof *par57),(*par58) = malloc(SIZE * sizeof *par58),(*par59) = malloc(SIZE * sizeof *par59),(*par60) = malloc(SIZE * sizeof *par60),(*par61) = malloc(SIZE * sizeof *par61),(*par62) = malloc(SIZE * sizeof *par62),(*par63) = malloc(SIZE * sizeof *par63),(*par64) = malloc(SIZE * sizeof *par64),(*par65) = malloc(SIZE * sizeof *par65),(*par66) = malloc(SIZE * sizeof *par66),(*par67) = malloc(SIZE * sizeof *par67),(*par68) = malloc(SIZE * sizeof *par68),(*par69) = malloc(SIZE * sizeof *par69),(*par70) = malloc(SIZE * sizeof *par70),(*par71) = malloc(SIZE * sizeof *par71),(*par72) = malloc(SIZE * sizeof *par72),(*par73) = malloc(SIZE * sizeof *par73),(*par74) = malloc(SIZE * sizeof *par74),(*par75) = malloc(SIZE * sizeof *par75),(*par76) = malloc(SIZE * sizeof *par76),(*par77) = malloc(SIZE * sizeof *par77),(*par78) = malloc(SIZE * sizeof *par78),(*par79) = malloc(SIZE * sizeof *par79),(*par80) = malloc(SIZE * sizeof *par80),(*par81) = malloc(SIZE * sizeof *par81),(*par82) = malloc(SIZE * sizeof *par82),(*par83) = malloc(SIZE * sizeof *par83),(*par84) = malloc(SIZE * sizeof *par84),(*par85) = malloc(SIZE * sizeof *par85),(*par86) = malloc(SIZE * sizeof *par86),(*par87) = malloc(SIZE * sizeof *par87),(*par88) = malloc(SIZE * sizeof *par88);
    int tempneg;    float temp1=0;    float temp2=0;    float temp3=0;    int attherow;
    float close;
    float rsivalue;
    float roc1value;
    float roc2value;
    float linangpriceval;
    float linlinangpriceval;
    float linangprice2val;
    float linlinangprice2val;
    float linangvolval;
    float linlinangvolval;
    float linangvol2val;
    float linlinangvol2val;

    while (1){
    printf("\n\nroclinlin===GEN %d===Biggest win ratio is %f and biggest prize is %f\n",generation,biggestwinratio,biggestprize);
        generation++;
    // ============================= file, delimiter, first_line_is_header?==============================
    CsvParser *data = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\data180d3m.csv", ",", 0);
    //create a second shadow to get the row number
    CsvParser *data2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\data180d3m.csv", ",", 0);
    //create class  for indicator csvs ---100---------------------------
    CsvParser *rsi = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180drsi3m.csv", ",", 0);

    CsvParser *roc1 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180droc13m.csv", ",", 0);
    CsvParser *roc2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180droc23m.csv", ",", 0);

    CsvParser *linangprice = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinangprice3m.csv", ",", 0);
    CsvParser *linlinangprice = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinlinangprice3m.csv", ",", 0);

    CsvParser *linangprice2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinangprice23m.csv", ",", 0);
    CsvParser *linlinangprice2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinlinangprice23m.csv", ",", 0);

    CsvParser *linangvol = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinangvol3m.csv", ",", 0);
    CsvParser *linlinangvol = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinlinangvol3m.csv", ",", 0);

    CsvParser *linangvol2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinangvol23m.csv", ",", 0);
    CsvParser *linlinangvol2 = CsvParser_new("C:\\Users\\yavuz\\Desktop\\Ctest\\180dlinlinangvol23m.csv", ",", 0);
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
    CsvRow *linangpricerows;
    CsvRow *linlinangpricerows;
    CsvRow *linangprice2rows;
    CsvRow *linlinangprice2rows;
    CsvRow *linangvolrows;
    CsvRow *linlinangvolrows;
    CsvRow *linangvol2rows;
    CsvRow *linlinangvol2rows;
    //print the number of rows:-------------------------
    printf("Number of rows=%d \n",numofrows);
    //["Open_time", "Open", "High", "Low", "Close", "Volume", "Close_time", "qav", "noot", "tbbav","tbqav", "ignore"]
    //follow row number "attherow"
    attherow=0;
    //field names in the rows for candle stick data
    char thename[][15]={"Open_time", "Open", "High", "Low", "Close", "Volume", "Close_time", "qav", "noot", "tbbav","tbqav", "ignore"};
 //assign random min max parameters
    for (int i=0;i<SIZE;i++){
        indexes[i]=i; choosenindexes[i]=0;
        cellinfo1[i]=0;cellinfo4[i]=0;cellinfo5[i]=0; cellinfo6[i]=0; cellinfo2[i]=0; cellinfo3[i]=0; cellinfo8[i]=0;cellinfo7[i]=1; //reseting cumulative prize,number of sales,number of wins,control number, selling ratio, buy price
        if (aliveordead[i]!=1){     //ilk kez atama yapılıyorsa hücre burada canlanacak, bir önceki turdan çıkanların değerlerini sıfırlamamak için bu şart var.
            /*intparameters(0,100,1,0,&par1[i],&par2[i]);
            intparameters(0,100,1,0,&par3[i],&par4[i]);
            intparameters(0,100,1,0,&par5[i],&par6[i]);
            intparameters(0,100,1,0,&par7[i],&par8[i]);
            /******NEGATIVE DECIMAL PARAMETERS******************ROC1,ROC2
            floatparameters(0,500,0.01,1,&par9[i],&par10[i]);
            floatparameters(0,500,0.01,1,&par11[i],&par12[i]);
            floatparameters(0,500,0.01,1,&par13[i],&par14[i]);
            floatparameters(0,500,0.01,1,&par15[i],&par16[i]);
            floatparameters(0,500,0.01,1,&par17[i],&par18[i]);
            floatparameters(0,500,0.01,1,&par19[i],&par20[i]);
            floatparameters(0,500,0.01,1,&par21[i],&par22[i]);
            floatparameters(0,500,0.01,1,&par23[i],&par24[i]);
            //*******NEGATIVE INT PARAMETERS***************LINANGPRICE*/
floatparameters(0,50,0.1,1,&par25[i],&par26[i]);    //linangpriceval
floatparameters(0,50,0.1,1,&par27[i],&par28[i]);
floatparameters(0,50,0.1,1,&par29[i],&par30[i]);
floatparameters(0,50,0.1,1,&par31[i],&par32[i]);

floatparameters(0,90,1,1,&par33[i],&par34[i]);    //linlinangpriceval
floatparameters(0,90,1,1,&par35[i],&par36[i]);
floatparameters(0,90,1,1,&par37[i],&par38[i]);
floatparameters(0,90,1,1,&par39[i],&par40[i]);

floatparameters(0,90,0.1,1,&par41[i],&par42[i]);//linangprice2val
floatparameters(0,90,0.1,1,&par43[i],&par44[i]);
floatparameters(0,90,0.1,1,&par45[i],&par46[i]);
floatparameters(0,90,0.1,1,&par47[i],&par48[i]);

floatparameters(0,90,0.1,1,&par49[i],&par50[i]); //linlinangprice2val
floatparameters(0,90,0.1,1,&par51[i],&par52[i]);
floatparameters(0,90,0.1,1,&par53[i],&par54[i]);
floatparameters(0,90,0.1,1,&par55[i],&par56[i]);

floatparameters(0,90,1,1,&par57[i],&par58[i]);//linangvolval
floatparameters(0,90,1,1,&par59[i],&par60[i]);
floatparameters(0,90,1,1,&par61[i],&par62[i]);
floatparameters(0,90,1,1,&par63[i],&par64[i]);

floatparameters(0,90,1,1,&par65[i],&par66[i]);//linlinangvolval
floatparameters(0,90,1,1,&par67[i],&par68[i]);
floatparameters(0,90,1,1,&par69[i],&par70[i]);
floatparameters(0,90,1,1,&par71[i],&par72[i]);

floatparameters(0,90,1,1,&par73[i],&par74[i]);//linangvol2val
floatparameters(0,90,1,1,&par75[i],&par76[i]);
floatparameters(0,90,1,1,&par77[i],&par78[i]);
floatparameters(0,90,1,1,&par79[i],&par80[i]);

floatparameters(0,90,1,1,&par81[i],&par82[i]);//linlinangvol2val
floatparameters(0,90,1,1,&par83[i],&par84[i]);
floatparameters(0,90,1,1,&par85[i],&par86[i]);
floatparameters(0,90,1,1,&par87[i],&par88[i]);
aliveordead[i]=1;       //atama yapılan hücre canlandırılır
            }
        //printf("\n %f   %f\n",par9[i],par10[i]);
    }
    sortedindexes=indexes;
    printf("\n Cells produced %d \n",SIZE);

    //pass the data ROW BY ROW then destroy the row

    while ((row = CsvParser_getRow(data)) ) {
    	//printf("\n==%d LINE==\n",++attherow);
    	// ********indicator row call*****
    	rsirows=CsvParser_getRow(rsi);
    	roc1rows=CsvParser_getRow(roc1);
    	roc2rows=CsvParser_getRow(roc2);
    	linangpricerows=CsvParser_getRow(linangprice);
    	linlinangpricerows=CsvParser_getRow(linlinangprice);
    	linangprice2rows=CsvParser_getRow(linangprice2);
    	linlinangprice2rows=CsvParser_getRow(linlinangprice2);
    	linangvolrows=CsvParser_getRow(linangvol);
    	linlinangvolrows=CsvParser_getRow(linlinangvol);
    	linangvol2rows=CsvParser_getRow(linangvol2);
    	linlinangvol2rows=CsvParser_getRow(linlinangvol2);

    	//*************data row ***************  standart input row as open,close etc.
        const char **rowFields = CsvParser_getFields(row);
        //value array, values in the row for **** indicator******
        const char **rsirowvalue = CsvParser_getFields(rsirows);
        const char **roc1rowvalue = CsvParser_getFields(roc1rows);
        const char **roc2rowvalue = CsvParser_getFields(roc2rows);
        const char **linangpricerowvalue = CsvParser_getFields(linangpricerows);
        const char **linlinangpricerowvalue = CsvParser_getFields(linlinangpricerows);

        const char **linangprice2rowvalue = CsvParser_getFields(linangprice2rows);
        const char **linlinangprice2rowvalue = CsvParser_getFields(linlinangprice2rows);

        const char **linangvolrowvalue = CsvParser_getFields(linangvolrows);
        const char **linlinangvolrowvalue = CsvParser_getFields(linlinangvolrows);

        const char **linangvol2rowvalue = CsvParser_getFields(linangvol2rows);
        const char **linlinangvol2rowvalue = CsvParser_getFields(linlinangvol2rows);
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
        linangpriceval = strtod(linangpricerowvalue[0], NULL);
        linlinangpriceval = strtod(linlinangpricerowvalue[0], NULL);
        linangprice2val = strtod(linangprice2rowvalue[0], NULL);
        linlinangprice2val = strtod(linlinangprice2rowvalue[0], NULL);
        linangvolval = strtod(linangvolrowvalue[0], NULL);
        linlinangvolval = strtod(linlinangvolrowvalue[0], NULL);
        linangvol2val = strtod(linangvol2rowvalue[0], NULL);
        linlinangvol2val = strtod(linlinangvol2rowvalue[0], NULL);
        //pass through cells
        for (int i=0;i<SIZE;i++){
                if ((cellinfo5[i]>attherow+800)&&(cellinfo4[i]==0)){//afk kalma yeniden üretime girme zaman aşım süresi
                    aliveordead[i]=0;
        indexes[i]=i; choosenindexes[i]=0;
        cellinfo1[i]=0;cellinfo4[i]=0;cellinfo5[i]=0; cellinfo6[i]=0; cellinfo2[i]=0; cellinfo3[i]=0; cellinfo8[i]=0;cellinfo7[i]=1; //reseting cumulative prize,number of sales,number of wins,control number, selling ratio, buy price
        if (aliveordead[i]!=1){     //ilk kez atama yapılıyorsa hücre burada canlanacak, bir önceki turdan çıkanların değerlerini sıfırlamamak için bu şart var.
            /*intparameters(0,100,1,0,&par1[i],&par2[i]);
            intparameters(0,100,1,0,&par3[i],&par4[i]);
            intparameters(0,100,1,0,&par5[i],&par6[i]);
            intparameters(0,100,1,0,&par7[i],&par8[i]);
            /******NEGATIVE DECIMAL PARAMETERS******************ROC1,ROC2
            floatparameters(0,500,0.01,1,&par9[i],&par10[i]);
            floatparameters(0,500,0.01,1,&par11[i],&par12[i]);
            floatparameters(0,500,0.01,1,&par13[i],&par14[i]);
            floatparameters(0,500,0.01,1,&par15[i],&par16[i]);
            floatparameters(0,500,0.01,1,&par17[i],&par18[i]);
            floatparameters(0,500,0.01,1,&par19[i],&par20[i]);
            floatparameters(0,500,0.01,1,&par21[i],&par22[i]);
            floatparameters(0,500,0.01,1,&par23[i],&par24[i]);
            //*******NEGATIVE INT PARAMETERS***************LINANGPRICE*/
floatparameters(0,50,0.1,1,&par25[i],&par26[i]);    //linangpriceval
floatparameters(0,50,0.1,1,&par27[i],&par28[i]);
floatparameters(0,50,0.1,1,&par29[i],&par30[i]);
floatparameters(0,50,0.1,1,&par31[i],&par32[i]);

floatparameters(0,90,1,1,&par33[i],&par34[i]);    //linlinangpriceval
floatparameters(0,90,1,1,&par35[i],&par36[i]);
floatparameters(0,90,1,1,&par37[i],&par38[i]);
floatparameters(0,90,1,1,&par39[i],&par40[i]);

floatparameters(0,90,0.1,1,&par41[i],&par42[i]);//linangprice2val
floatparameters(0,90,0.1,1,&par43[i],&par44[i]);
floatparameters(0,90,0.1,1,&par45[i],&par46[i]);
floatparameters(0,90,0.1,1,&par47[i],&par48[i]);

floatparameters(0,90,0.1,1,&par49[i],&par50[i]); //linlinangprice2val
floatparameters(0,90,0.1,1,&par51[i],&par52[i]);
floatparameters(0,90,0.1,1,&par53[i],&par54[i]);
floatparameters(0,90,0.1,1,&par55[i],&par56[i]);

floatparameters(0,90,1,1,&par57[i],&par58[i]);//linangvolval
floatparameters(0,90,1,1,&par59[i],&par60[i]);
floatparameters(0,90,1,1,&par61[i],&par62[i]);
floatparameters(0,90,1,1,&par63[i],&par64[i]);

floatparameters(0,90,1,1,&par65[i],&par66[i]);//linlinangvolval
floatparameters(0,90,1,1,&par67[i],&par68[i]);
floatparameters(0,90,1,1,&par69[i],&par70[i]);
floatparameters(0,90,1,1,&par71[i],&par72[i]);

floatparameters(0,90,1,1,&par73[i],&par74[i]);//linangvol2val
floatparameters(0,90,1,1,&par75[i],&par76[i]);
floatparameters(0,90,1,1,&par77[i],&par78[i]);
floatparameters(0,90,1,1,&par79[i],&par80[i]);

floatparameters(0,90,1,1,&par81[i],&par82[i]);//linlinangvol2val
floatparameters(0,90,1,1,&par83[i],&par84[i]);
floatparameters(0,90,1,1,&par85[i],&par86[i]);
floatparameters(0,90,1,1,&par87[i],&par88[i]);
aliveordead[i]=1;       //atama yapılan hücre canlandırılır
            }
                }
                if (aliveordead[i]==1){
        //  ---------------------------------------bot movement area----------------------------------------------------------------------------
         //***BUY trigger*******

        if ((cellinfo3[i]==0)&&(par25[i]<linangpriceval) && (linangpriceval<par26[i])&&(par33[i]<linlinangpriceval) && (linlinangpriceval<par34[i])&&(par41[i]<linangprice2val) && (linangprice2val<par42[i])&&(par49[i]<linlinangprice2val) && (linlinangprice2val<par50[i])&&(par57[i]<linangvolval) && (linangvolval<par58[i])&&(par65[i]<linlinangvolval) && (linlinangvolval<par66[i])&&(par73[i]<linangvol2val) && (linangvol2val<par74[i])&&(par81[i]<linlinangvol2val) && (linlinangvol2val<par82[i])){
        cellinfo3[i]=0.5;
        cellinfo4[i]=attherow;
        printf("\nTriggered %d",i);

        }
        //****BUY******
        else if ((cellinfo3[i]==0.5)&&(par27[i]<linangpriceval) && (linangpriceval<par28[i])&&(par35[i]<linlinangpriceval) && (linlinangpriceval<par36[i])&&(par43[i]<linangprice2val) && (linangprice2val<par44[i])&&(par51[i]<linlinangprice2val) && (linlinangprice2val<par52[i])&&(par59[i]<linangvolval) && (linangvolval<par60[i])&&(par67[i]<linlinangvolval) && (linlinangvolval<par68[i])&&(par75[i]<linangvol2val) && (linangvol2val<par76[i])&&(par83[i]<linlinangvol2val) && (linlinangvol2val<par84[i])){         //***********BUY************
            cellinfo3[i]=1;
            cellinfo7[i]=close; //alım fiyatını kaydeder
            cellinfo4[i]=attherow;
            cellinfo5[i]=attherow;
        printf("\nBought %d",i);
        }
        //*************SELL TRIGGER***********
        else if ((cellinfo3[i]==1)&&(par29[i]<linangpriceval) && (linangpriceval<par30[i])&&(par37[i]<linlinangpriceval) && (linlinangpriceval<par38[i])&&(par45[i]<linangprice2val) && (linangprice2val<par46[i])&&(par53[i]<linlinangprice2val) && (linlinangprice2val<par54[i])&&(par61[i]<linangvolval) && (linangvolval<par62[i])&&(par69[i]<linlinangvolval) && (linlinangvolval<par70[i])&&(par77[i]<linangvol2val) && (linangvol2val<par78[i])&&(par85[i]<linlinangvol2val) && (linlinangvol2val<par86[i])){         //***********SELL trigger************
        cellinfo3[i]=0.75;
        cellinfo4[i]=attherow;
        }
        //***********SELL**************
        else if ((cellinfo3[i]==0.75)&&(par31[i]<linangpriceval) && (linangpriceval<par32[i])&&(par39[i]<linlinangpriceval) && (linlinangpriceval<par40[i])&&(par47[i]<linangprice2val) && (linangprice2val<par48[i])&&(par55[i]<linlinangprice2val) && (linlinangprice2val<par56[i])&&(par63[i]<linangvolval) && (linangvolval<par64[i])&&(par71[i]<linlinangvolval) && (linlinangvolval<par72[i])&&(par79[i]<linangvol2val) && (linangvol2val<par80[i])&&(par87[i]<linlinangvol2val) && (linlinangvol2val<par88[i])){         //***********SELL************
        cellinfo3[i]=0;     // al sat bekle durum göstergesi
        cellinfo6[i]++;     //satış işlemi sayısı
        cellinfo8[i]=close/ cellinfo7[i]; //satımın alıma oranı
        cellinfo1[i]+=cellinfo8[i]-1; //biriken kar
        if ((cellinfo8[i]-1)>0.004){
            cellinfo2[i]++; //kar eden işlem sayısı
        }
        cellinfo4[i]=attherow;
        cellinfo5[i]=attherow;
        }
        }
        } //----------------------------------------------------------------------------------------------------------------------
        attherow++;
        CsvParser_destroy_row(row);
        CsvParser_destroy_row(rsirows);
        CsvParser_destroy_row(roc1rows);
        CsvParser_destroy_row(roc2rows);
        CsvParser_destroy_row(linangpricerows);
        CsvParser_destroy_row(linlinangpricerows);
        CsvParser_destroy_row(linangprice2rows);
        CsvParser_destroy_row(linlinangprice2rows);
        CsvParser_destroy_row(linangvolrows);
        CsvParser_destroy_row(linlinangvolrows);
        CsvParser_destroy_row(linangvol2rows);
        CsvParser_destroy_row(linlinangvol2rows);
    }
    temp1=0;//win ratio
    temp2=0;// cumulative prize cellinfo1[i];
    temp3=0;//cellinfo6/numofrows= willingness to make a move
    //*******************************************************determines the fitness here *******************************
    for (int i=0;i<SIZE;i++){
            if ((cellinfo6[i]==0.0)||(numofrows==0)||(cellinfo4[i]==0)){ //ZERO DIVISION ERROR OLMAMASI ICIN cellinfo6 MUTLAKA 0DAN BUYUK OLMALI DEÐÝLSE FITNESS=0 yap diyor bu if
                fitness[i]=-99;
                aliveordead[i]=0;
            }
            else{
                temp1=(cellinfo2[i]*1.0)/cellinfo6[i]; //profitted sales : total sales
                temp2=cellinfo1[i]; // cumulative prize
                temp3=(temp1+temp2/10.0)*10000*((cellinfo6[i]*3/(numofrows*1.0)));  //cellinfo6/numofrows= willingness to make a move
                fitness[i]=temp3;
            }
            if ((temp1>0.00)&& ((cellinfo6[i]/(numofrows*1.0)>0.000))){       //winrate >%30 -> ve hareketlilik > %xxx
            if ((biggestfactor<temp3)){     //temp3= total fittness including cellinfo6/numofrows= willingness to make a move
                biggestwinratio=temp1;
                biggestprize=temp2;
                biggestfactor=temp3;
                //printf("\n---\n%d.cell parameters are= %d RSIbuytrigger %d | %f ROCbuytrigger %f | %d rsibuy %d | %f ROCbuytrigger %f \n %d rsiselltrigger %d | %f ROCselltrigger %f| %d rsisell %d | %f ROCsell %f \nWinratio: %f , number of sell activity= %f , movement ratio= %f ,prize= %f , temp3=%f"\
                //,i,par1[i],par2[i],par25[i],par26[i],par3[i],par4[i],par27[i],par28[i],par5[i],par6[i],par29[i],par30[i],par7[i],par8[i],par31[i],par32[i],temp1,cellinfo6[i],(cellinfo6[i]/(numofrows*1.0)),temp2,temp3);
            }
        }
    }
    sortedfitness=fitness;
    sortthearray(sortedfitness,SIZE,sortedindexes);
    printf("\nSorted\n");
    //*************************************CHOOSE BEST CELLS*****************************
    temprepro=0;
    for (int i=0;i<(SIZE/30);i++){      //dnası kullanılacak maks populasyonun oranı seçiliyor.
            if (aliveordead[sortedindexes[i]]==1){      //Hücre canlı kalmışsa ancak seçilir.
                choosenindexes[temprepro]=sortedindexes[i];
                temprepro++;
                cellinfo1[i]=0;
                cellinfo2[i]=0;
                cellinfo3[i]=0;
                cellinfo4[i]=0;
                cellinfo5[i]=0;
                cellinfo6[i]=0;
                cellinfo7[i]=0;
                cellinfo8[i]=0;
            }
    }
    numberofparents=temprepro; //seçilen hücre sayısı
    printf("\nNumber of parents=%d",temprepro);
    //********************************CREATE NEW CELLS************************ multi-point uniform crossover
    temprepro=0;    //n th cell
    temprepro2=0; //number of cells produced from 2 x "n th cell"
    tempneg=0;tempinx1=0;tempinx2=0;
    for(int ii=0;ii<SIZE;ii++){
            if ((temprepro>=SIZE)||(numberofparents==0)||(aliveordead[ii]==1)||(temprepro2>=(SIZE/30)*numberofchildperselected)){
                continue;
            }
            else{
                aliveordead[tempinx]=1;     //sondan baslayarak olu hucreleri yavruya donusturecek
                /*List of parameters
                tempneg=rand()%(numberofparents+1);
                par1[tempinx]=par1[tempinx1];
                par2[tempinx]=par2[tempinx1];
                //--------
                tempneg=rand()%(numberofparents+1);
                par3[tempinx]=par3[tempinx1];
                par4[tempinx]=par4[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par5[tempinx]=par5[tempinx1];
                par6[tempinx]=par6[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par7[tempinx]=par7[tempinx1];
                par8[tempinx]=par8[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par9[tempinx]=par9[tempinx1];
                par10[tempinx]=par10[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par11[tempinx]=par11[tempinx1];
                par12[tempinx]=par12[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par13[tempinx]=par13[tempinx1];
                par14[tempinx]=par14[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par15[tempinx]=par15[tempinx1];
                par16[tempinx]=par16[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par17[tempinx]=par17[tempinx1];
                par18[tempinx]=par18[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par19[tempinx]=par19[tempinx1];
                par20[tempinx]=par20[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par21[tempinx]=par21[tempinx1];
                par22[tempinx]=par22[tempinx1];
                //------------
                tempneg=rand()%(numberofparents+1);
                par23[tempinx]=par23[tempinx1];
                par24[tempinx]=par24[choosenindexes[tempneg]];
                //------------*/
if (temprepro*2<numberofparents-1){
    tempneg=temprepro*2;
    temprepro++;
    tempinx1=choosenindexes[tempneg];
    tempinx2=choosenindexes[tempneg+1];
}
else {
    tempneg=rand()%(numberofparents);
    tempinx1=choosenindexes[tempneg];
    tempinx2=choosenindexes[tempneg+1];
}

temprepro2++;//üretlen hücre miktarı
par25[tempinx]=par25[tempinx1];
par26[tempinx]=par26[tempinx2];
//------------
par27[tempinx]=par27[tempinx1];
par28[tempinx]=par28[tempinx2];
//------------
par29[tempinx]=par29[tempinx1];
par30[tempinx]=par30[tempinx2];
//------------
par31[tempinx]=par31[tempinx1];
par32[tempinx]=par32[tempinx2];
//------------
par33[tempinx]=par33[tempinx1];
par34[tempinx]=par34[tempinx2];
//------------
par35[tempinx]=par35[tempinx1];
par36[tempinx]=par36[tempinx2];
//------------
par37[tempinx]=par37[tempinx1];
par38[tempinx]=par38[tempinx2];
//------------
par39[tempinx]=par39[tempinx1];
par40[tempinx]=par40[tempinx2];
//------------
par41[tempinx]=par41[tempinx1];
par42[tempinx]=par42[tempinx2];
//------------
par43[tempinx]=par43[tempinx1];
par44[tempinx]=par44[tempinx2];
//------------
par45[tempinx]=par45[tempinx1];
par46[tempinx]=par46[tempinx2];
//------------
par47[tempinx]=par47[tempinx1];
par48[tempinx]=par48[tempinx2];
//------------
par49[tempinx]=par49[tempinx1];
par50[tempinx]=par50[tempinx2];
//------------
par51[tempinx]=par51[tempinx1];
par52[tempinx]=par52[tempinx2];
//------------
par53[tempinx]=par53[tempinx1];
par54[tempinx]=par54[tempinx2];
//------------
par55[tempinx]=par55[tempinx1];
par56[tempinx]=par56[tempinx2];
//------------
par57[tempinx]=par57[tempinx1];
par58[tempinx]=par58[tempinx2];
//------------
par59[tempinx]=par59[tempinx1];
par60[tempinx]=par60[tempinx2];
//------------
par61[tempinx]=par61[tempinx1];
par62[tempinx]=par62[tempinx2];
//------------
par63[tempinx]=par63[tempinx1];
par64[tempinx]=par64[tempinx2];
//------------
par65[tempinx]=par65[tempinx1];
par66[tempinx]=par66[tempinx2];
//------------
par67[tempinx]=par67[tempinx1];
par68[tempinx]=par68[tempinx2];
//------------
par69[tempinx]=par69[tempinx1];
par70[tempinx]=par70[tempinx2];
//------------

par71[tempinx]=par71[tempinx1];
par72[tempinx]=par72[tempinx2];
//------------

par73[tempinx]=par73[tempinx1];
par74[tempinx]=par74[tempinx2];
//------------

par75[tempinx]=par75[tempinx1];
par76[tempinx]=par76[tempinx2];
//------------

par77[tempinx]=par77[tempinx1];
par78[tempinx]=par78[tempinx2];
//------------

par79[tempinx]=par79[tempinx1];
par80[tempinx]=par80[tempinx2];
//------------

par81[tempinx]=par81[tempinx1];
par82[tempinx]=par82[tempinx2];
//------------

par83[tempinx]=par83[tempinx1];
par84[tempinx]=par84[tempinx2];
//------------

par85[tempinx]=par85[tempinx1];
par86[tempinx]=par86[tempinx2];
//------------

par87[tempinx]=par87[tempinx1];
par88[tempinx]=par88[tempinx2];
    }}
    printf("\nNew generation with %d members has reproduced!",temprepro2);
    CsvParser_destroy(data);
    CsvParser_destroy(data2);
    CsvParser_destroy(rsi);
    CsvParser_destroy(roc1);
    CsvParser_destroy(roc2);

    CsvParser_destroy(linangprice);

    CsvParser_destroy(linlinangprice);
    CsvParser_destroy(linangprice2);

    CsvParser_destroy(linlinangprice2);
    CsvParser_destroy(linangvol);

    CsvParser_destroy(linlinangvol);
    CsvParser_destroy(linangvol2);

    CsvParser_destroy(linlinangvol2);
    }

    printf("\nEnter any key to terminate");
    scanf("\n%f",&close);
    return 0;
}
