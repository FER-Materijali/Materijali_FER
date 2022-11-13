import java.util.ArrayList;
import java.util.Locale.Category;

public class Knapsnack {

	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int maxWeight=14;
		int numThings=6;
		int numCateg=3;
		
		String[] kategorije=new String[]{"", "Tenisice", "Majica", "Kapa"};
		String[] proizvod=new String[]{"Lagane", "Bez rukava", "Kratka", "Duga", "Šilterica", "Šešir"};
		

		
		int[] vrijednost = new int[numThings+1];
		int[] cijena = new int[numThings+1];
		int[] kateg = new int[numThings+1];
		
		vrijednost[0]=6;
		cijena[0]=3;
		kateg[0]=1;

		vrijednost[1]=11;
		cijena[1]=5;
		kateg[1]=2;
	
		vrijednost[2]=10;
		cijena[2]=6;
		kateg[2]=2;
		
		vrijednost[3]=13;
		cijena[3]=10;
		kateg[3]=2;
		
		vrijednost[4]=4;
		cijena[4]=2;
		kateg[4]=3;
		
		vrijednost[5]=7;
		cijena[5]=10;
		kateg[5]=3;
		
		for(int stupac=0;stupac<numThings;stupac++){
			System.out.println("Kategorija:"+kategorije[kateg[stupac]]+" Opis: "+proizvod[stupac]+" Zadovoljstvo:"+vrijednost[stupac]+" Cijena:"+cijena[stupac]);
		}
		System.out.println();
		
		int myLeft=0;
		int remember=0;
		int[] count = new int[numCateg+1];

		for(int category=1; category<=numCateg; ++category){
			count[category]=0;
		}
		
		int[][] table = new int[maxWeight+1][numThings+1];

		int[][] keepTable = new int[maxWeight+1][numThings+1];
		
		for(int i=1; i<=maxWeight; ++i){
			for(int j=0; j<numThings; ++j){
				table[i][j]=0;
				keepTable[i][j]=0;
			}
		}
		
		for(int stvar=0; stvar<numThings;++stvar){
			myLeft=0;
			remember=0;
			
			if(kateg[stvar]==1){
				++count[kateg[stvar]];
				
				for(int redak=1; redak <= maxWeight ; redak++){
					if(cijena[stvar]<=redak){
						table[redak][stvar]=vrijednost[stvar];
						keepTable[redak][stvar]=1;
					}
				}
			}
			else{
				++count[kateg[stvar]];
				for(int redak=1; redak<=maxWeight;redak++){
					for(int i=0; i<count[kateg[stvar]-1];++i){
						if(table[redak][stvar-count[kateg[stvar]]-i]>myLeft){
							myLeft=table[redak][stvar-count[kateg[stvar]]-i];
						}
					}
					if(cijena[stvar]>redak){
						table[redak][stvar]=myLeft;
					}
					else{
						for(int i = 0; i<count[kateg[stvar]-1]; ++i){
							if(redak>cijena[stvar] && table[redak-cijena[stvar]][stvar-count[kateg[stvar]]-i]>remember){
								remember=table[redak-cijena[stvar]][stvar-count[kateg[stvar]]-i];
							}
						}
						int sum = remember+vrijednost[stvar];
						if(sum>=myLeft){
							table[redak][stvar]=sum;
							keepTable[redak][stvar]=1;
						}
						else{
							table[redak][stvar]=myLeft;
						}
					}
				}
			}
		}
		
		for(int i=1;i<=maxWeight;i++){
			for(int j=0; j<numThings; j++){
				System.out.printf("%d\t",  table[i][j]);
			}
			System.out.println();
		}

		System.out.println();
		for(int i=1;i<=maxWeight;i++){
			for(int j=0; j<numThings; j++){
				System.out.printf("%d\t",  keepTable[i][j]);
			}
			System.out.println();
		}

		int k=maxWeight;
		int stupac=numThings;
		int brkat=numCateg;
		System.out.println("Najbolji odabir:");
		while(true){
			if(keepTable[k][stupac]==0){
				stupac--;
				if(stupac<0) break;
			}
			else{
				if(stupac<0 || k<0) break;
				System.out.println("Kategorija:"+kategorije[kateg[stupac]]+" Opis: "+proizvod[stupac]+" Zadovoljstvo:"+vrijednost[stupac]+" Cijena:"+cijena[stupac]);
				
				k=k-cijena[stupac];
				stupac-=count[brkat-1];
				brkat-=1;
				if(brkat==0) break;
			}
		}
		
		
		
		
	
	}

}
