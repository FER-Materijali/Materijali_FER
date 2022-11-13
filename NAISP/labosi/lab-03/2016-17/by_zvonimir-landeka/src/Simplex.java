
/**
 * @author Zvonimir Landeka
 *
 */
public class Simplex {
	private double[][] table = new double[4][7];	
	private int maxRow;
	private int maxColumn;
	private int numRow;
	private int numColumn;
	String[] stupci;
	String[] retci;
	public Simplex(){
		numRow=4;
		numColumn=7;
		maxRow=numRow-1;
		maxColumn=numColumn-1;
		stupci=new String[]{"x1", "x2", "s1", "s2", "s3", "z", ""};
		retci=new String[]{"s1", "s2", "s3", "z"};
	}
	
	public void start(){
		fillTable();
		ispisiTablicu();
		while(true){
			
			double minimum=0;
			int pivotColumn=-1;
			int pivotRow=-1;
			double pivot;
			//TRAZENJE PIVOT COLUMNa 
			for(int i = 0; i<numColumn; i++){
				
				if(minimum > table[maxRow][i]){
					minimum=table[maxRow][i];
					pivotColumn=i;
				}
			}
			//AKO JE VRIJEDNOST POZITIVNA ONDA SMO ZAVRSILI SA ITERIRANJEM
			if(minimum>=0){
				break;
			}
			//TRAZENJE PIVOT ROWa
			double minimumPivotRow = -1;
			for(int j=0; j<numRow-1; j++){
				double izracunati=table[j][maxColumn]/table[j][pivotColumn];
				if(izracunati>=0){
					if(minimumPivotRow==-1 || minimumPivotRow>izracunati){
						minimumPivotRow=izracunati;
						pivotRow=j;
					}
				}
			}
			pivot=table[pivotRow][pivotColumn];
			System.out.println("Pivot je broj: "+ pivot + " Na lokaciji ("+pivotRow+","+pivotColumn+") tj. ("+ retci[pivotRow]+","+stupci[pivotColumn]+")"  );
			//izbacivanje s-a i stavljanje x-a
			if(stupci[pivotColumn].contains("x")){
				System.out.println("Stožerni razvoj: " + retci[pivotRow] + " izlazi iz rjesenja, ulazi: " + stupci[pivotColumn]);
				retci[pivotRow]=stupci[pivotColumn];
			}
			
			
			//PUNJENJE PIVOT ROWa 
			
			for(int i=0; i<numColumn; i++){
				table[pivotRow][i]=table[pivotRow][i]/pivot;
				if(table[pivotRow][i]==-0){
					table[pivotRow][i]=0;
				}
			}
			//PUNJENJE OSTALIH REDOVA
			for(int i = 0; i<numRow;i++){
				if(i!=pivotRow){
					double pivotRetka=table[i][pivotColumn];
					for(int j = 0; j<numColumn; j++){
//						System.out.println("= "+ table[i][j]+ " - " + table[i][pivotColumn]+"*" + table[pivotRow][j]);
						table[i][j]=table[i][j] - (pivotRetka*table[pivotRow][j]);
					}
				}
			}
			System.out.println();
			System.out.println("Punjenje tablice:");
			ispisiTablicu();
			
		}	
		
		
		
		
	}

	private void ispisiTablicu() {
		System.out.print("\t");
		for(int i=0; i< stupci.length;i++){
			System.out.print(stupci[i]+"\t");
		}
		System.out.println();
		for(int i=0; i<numRow; i++){
			System.out.print(retci[i]+"\t");
			for(int j=0; j<numColumn; j++){
				System.out.printf("%3.3f\t", table[i][j]);
			}
			System.out.println();
		}
		
	}

	private void fillTable() {
//		double[] row0=new double[]{1,1,1,0,0,0,10};
//		double[] row1=new double[]{-1,-1,0,1,0,0,-7};
//		double[] row2=new double[]{1,2,0,0,1,0,12};
//		double[] row3=new double[]{-1300,-1500,0,0,0,1,0};
		double[] row0=new double[]{3,4,1,0,0,0,15};
		double[] row1=new double[]{25,50,0,1,0,0,150};
		double[] row2=new double[]{-2,-5,0,0,1,0,-11};
		double[] row3=new double[]{-65,-90,0,0,0,1,0};
		table[0]=row0;
		table[1]=row1;
		table[2]=row2;
		table[3]=row3;
	}
	
}
