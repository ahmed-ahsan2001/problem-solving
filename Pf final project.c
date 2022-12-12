#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define PI  3.141592653589793238
#define MAX 15
FILE *fdisplay_03;
FILE *fdisplay_04;
FILE *fdisplay_05;
FILE *fp;
FILE *fptrconic;
int section1();
int section3();
int section2();
void ellipse(float *a,float *b,float *c);
void hyperbola1(float a,float b,float C,float D,float F,float z);
void hyperbola2(float a,float b,float C,float D,float F,float z);
void hyperbola3(float a,float b,float C,float D,float F,float z);
void hyperbola4(float a,float b,float C,float D,float F,float z);
void hyperbola(float *a,float *b,float *c);
int det3by3();
int transpose3x3();
int inverse2x2();
int inverse3x3();
int det2by2();
int singular2x2();
int singular3x3();
int adjoint3x3();
int adjoint2x2();
int transpose2x2();
FILE *fp1;
int main(){
	int z;
	fp1=fopen("set.txt","w");
	while(1){
		system("cls");
		printf("\t\t----Software to perform calculation on matrix,conic and triangles----");
		printf("\n1.Section 1(Conic)\n2.Section 2(Matrix)\n3.Section 3(Triangles)\n4.Exit and show my result summary\nEnter Your Choice:");
		scanf("%d",&z);
		if(z==1)
		    section1();
		if(z==2)
		    section2();
		if(z==3)
		    section3();
		if(z==4)
			break;
	}
	system("cls");
	printf("The summary of your calculations is\n");
	fclose(fp1);
	char c;
	fp1=fopen("set.txt","r");
	while (c != EOF) { 
	c = fgetc(fp1);
    printf ("%c",c); };
    fclose(fp1);
    getch();
}
int section1(){
	system("cls");
	char str[150];
	int no;
	char c;
	fptrconic=fopen("conic.txt","r");
	fscanf(fptrconic," %[^\0]",str);
	printf ("%s",str); 
    fclose(fptrconic);
	scanf("%d",&no);
	if(no==1){
		system("cls");
		float a,b,c,m;
		printf("Enter equation in the form ax+by+c=0 to find slope\n");
		printf("a:");
	    scanf(" %f",&a);
	    printf("b:");
	    scanf(" %f",&b);
	    printf("c:");
	    scanf(" %f",&c);
	    if(b==0){
		
	    	printf("Slope is infinite as line is parallel to y axis");
	    	fprintf(fp1,"Slope is infinite as line is parallel to y axis\n");}
		else{
			m=-a/b;
	        printf("slope=%f",m);
	        fprintf(fp1,"slope=%f\n",m);
		}
	}
	if(no==2){
		system("cls");
		float a1,b1,c1,a2,b2,c2;
	    float x,y;
	    printf("Solving Two linear equations in the form a1x+b1y+c1=0 a2x+b2x+c2=0 to find their solution set\nEnter the values a1,b1,c1,a2,b2 and c2:\n");
        printf("a1:");
	    scanf(" %f",&a1);
	    printf("b1:");
	    scanf(" %f",&b1);
	    printf("c1:");
	    scanf(" %f",&c1);
	    printf("a2:");
	    scanf(" %f",&a2);
	    printf("b2:");
	    scanf(" %f",&b2);
 	    printf("c2:");
	    scanf(" %f",&c2);
		if(((a1*b2)-(a2*b1))==0){
		
		    printf("Lines are parallel hence they are not intersecting");
		    fprintf(fp1,"Lines are parallel hence they are not intersecting");}
		else{
	        x=((b1*c2)-(c1*b2))/((a1*b2)-(a2*b1));
            y=((a2*c1)-(a1*c2))/((a1*b2)-(a2*b1));
	        printf("x=%f y=%f",x,y);
	        fprintf(fp1,"x=%f y=%f",x,y);
		}
}
    if(no==3){
    	system("cls");
    	float a1,b1,c1,a2,b2,c2,a3,b3,c3,d1,d2,d3;
	    float x,y,z,A;
	    printf("Solving Three linear equation in the form a1x+b1y+c1z+d1=0 a2x+b2x+c2z+d2=0 a3x+b3y+c3z+d3=0 to find their solution set\nEnter the values a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3 and d3\n");
        printf("First linear equation a1x+b1y+c1z+d1=0 Enter a1,b1,c1,d1:");
	    scanf("%f%f%f%f",&a1,&b1,&c1,&d1);
	    printf("Second linear equation a2x+b2y+c2z+d2=0 Enter a2,b2,c2,d2:");
	    scanf("%f%f%f%f",&a2,&b2,&c2,&d2);
	    printf("Third linear equation a3x+b3y+c3z+d3=0 Enter a3,b3,c3,d3:");
	    scanf("%f%f%f%f",&a3,&b3,&c3,&d3);
	    if((a1*(b2*c3-c2*b3)-b1*(a2*c3-c2*a3)+c1*(a2*b3-b2*a3))!=0){
	    	A=a1*(b2*c3-c2*b3)-b1*(a2*c3-c2*a3)+c1*(a2*b3-b2*a3);
	    	x=(((-d1)*(b2*c3-c2*b3)-b1*((-d2)*c3-c2*(-d3))+c1*((-d2)*b3-b2*(-d3))))/(A);
	    	y=(a1*((-d2)*c3-c2*(-d3))-(-d1)*(a2*c3-c2*a3)+c1*(a2*(-d3)-(-d2)*a3))/(A);
	    	z=((a1*(b2*(-d3)-(-d2)*b3)-b1*(a2*(-d3)-(-d2)*a3)+(-d1)*(a2*b3-b2*a3)))/(A);
	    	printf(" \tx=%f\ty=%f\tz=%f",x,y,z);
	    	fprintf(fp1," \tx=%f\ty=%f\tz=%f",x,y,z);
		}
		else
		printf("\nLines do not intersect solution is not possible\n ");
	}
	if(no==4){
		system("cls");
		printf("\nTo find distance between two points/coordinates\n");
		float x1,y1,x2,y2,d;
		printf("Enter (x1,y1):");
		scanf("%f%f",&x1,&y1);
		printf("Enter (x2,y2):");
		scanf("%f%f",&x2,&y2);
		d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		printf("\nDistance between two points is %f\n",d);
		fprintf(fp1,"\nDistance between two points is %f\n",d);
	}
	if(no==5){
		system("cls");
		printf("\nTo find distance between a point(x1,y1) and a line ax+by+c=0\n");
		float x1,y1,a,b,c,d=0;
		printf("Enter (x1,y1):");
		scanf("%f%f",&x1,&y1);
		printf("Enter equation in the form ax+by+c=0\na:");
	    scanf(" %f",&a);
	    printf("b:");
	    scanf(" %f",&b);
	    printf("c:");
	    scanf(" %f",&c);
	    d=(a*x1+b*y1+c)/(sqrt(a*a+b*b));
	    printf("The distance between the line and point is d=%f units",d<0?-d:d);
	    fprintf(fp1,"The distance between the line and point is d=%f units",d<0?-d:d);
	}
    if(no==6){
    	system("cls");
    	printf("To find radius of circle and its centre point coordinates\n");
    	printf("Enter the form in which you want to enter equation of circle\n1.(x-a)^2+(y-b)^2=r^2\n2.ax^2+ay^2+2gx+2fy+c=0\nEnter your choice:");
    	int number;
    	scanf("%d",&number);
    	if(number==1){
    		float a,b,r2;
    		float r;
    		printf("Enter a:");
    		scanf("%f",&a);
    		printf("Enter b:");
    		scanf("%f",&b);
    		printf("Enter r^2:");
    		scanf("%f",&r2);
    		printf("Center point of circle is c(%f,%f)\n",a,b);
    		fprintf(fp1,"Center point of circle is c(%f,%f)\n",a,b);
    		r=sqrt(r2);
    		r2<0?printf("Invalid radius as the equation does not determine a circle"):printf("Radius of circle is %f unitssq",r);
    		r2<0?fprintf(fp1,"Invalid radius as the equation does not determine a circle"):fprintf(fp1,"Radius of circle is %f unitssq",r);
		}
		else if(number==2){
			int a;
			printf("Enter a:");
			scanf("%d",&a);
			 if(a>=1){
				float r,c,g,f,G,F,C;
				printf("Enter coefficient of x i.e 2g:");
    		    scanf("%f",&g);
    		    printf("Enter coefficient of y i.e 2f:");
    		    scanf("%f",&f);
    		    printf("Enter c:");
    		    scanf("%f",&c);
    		    G=-g/(a*2);
    		    F=-f/(a*2);
    		    C=c/a;
				printf("Center of circle is C(%f,%f)\n",G,F);
				fprintf(fp1,"Center of circle is C(%f,%f)\n",G,F);
				r=sqrt((G*G)+(F*F)-(C));
				(G*G)+(F*F)-(C)<0?printf("Invalid radius as the equation does not determine a circle"):printf("Radius of circle is %f unitssq",r);
				(G*G)+(F*F)-(C)<0?fprintf(fp1,"Invalid radius as the equation does not determine a circle"):fprintf(fp1,"Radius of circle is %f unitssq",r);
			}
			else{
				float r,c,g,f,G,F,C;
				printf("Enter coefficient of x i.e 2g:");
    		    scanf("%f",&g);
    		    printf("Enter coefficient of y i.e 2f:");
    		    scanf("%f",&f);
    		    printf("Enter c:");
    		    scanf("%f",&c);
    		    a=-a;
    		    g=-g;
    		    f=-f;
    		    c=-c;
    		    G=-g/(a*2);
    		    F=-f/(a*2);
    		    C=c/a;
				printf("Center of circle is C(%f,%f)\n",G,F);
				fprintf(fp1,"Center of circle is C(%f,%f)\n",G,F);
				r=sqrt((G*G)+(F*F)-(C));
				(G*G)+(F*F)-(C)<0?printf("Invalid radius as the equation does not determine a circle"):printf("Radius of circle is %f unitssq",r);
				(G*G)+(F*F)-(C)<0?fprintf(fp1,"Invalid radius as the equation does not determine a circle"):fprintf(fp1,"Radius of circle is %f unitssq",r);
			}
		}  	
	}
	if(no==7){
		system("cls");
		int choice;
		printf("To solve the equation of ellipse and find its coordinates of major axis,minor axis and focii\nEcentricity and length of latus rectum.\n1.ax^2+by^2=c\n2.ax^2+by^2+Cx+Dy+F=0");
		scanf("%d",&choice);
		float a,b,c,e,l,z,C,D,F,h,k,swap;
		if(choice==1){
		printf("\nax^2+by^2=c\nEnter the values of a,b,c\n");
		scanf("%f%f%f",&a,&b,&c);
		a=sqrt(c/a);
		b=sqrt(c/b);
		if(b>a){
			ellipse(&b,&a,&c);
			printf("Major axis is along y axis\nCoordinates of major axis(0,%f),(0,%f)\nCoordinates of minor axis(%f,0),(%f,0)",b,-b,a,-a);
			printf("\nCordinates of focii(0,%f),(0,%f)\n",c,-c);
			fprintf(fp1,"Major axis is along y axis\nCoordinates of major axis(0,%f),(0,%f)\nCoordinates of minor axis(%f,0),(%f,0)",b,-b,a,-a);
			fprintf(fp1,"\nCordinates of focii(0,%f),(0,%f)\n",c,-c);
		}
		else{
			ellipse(&a,&b,&c);
			printf("Major axis is along x axis\nCoordinates of major axis(%f,0),(%f,0)\nCoordinates of minor axis(0,%f),(0,%f)",a,-a,b,-b);
			printf("\nCordinates of focii(%f,0),(%f,0)\n",c,-c);
			fprintf(fp1,"Major axis is along x axis\nCoordinates of major axis(%f,0),(%f,0)\nCoordinates of minor axis(0,%f),(0,%f)",a,-a,b,-b);
			fprintf(fp1,"\nCordinates of focii(%f,0),(%f,0)\n",c,-c);
		}	
		}
		if(choice==2){
		printf("ax^2+by^2+Cx+Dy+F=0   Enter the values of a,b,C,D,F");
		scanf("%f%f%f%f%f",&a,&b,&C,&D,&F);
			z=-F+a*(C/(2*a))*(C/(2*a))+b*(D/(2*b))*(D/(2*b));
			h=-(C/(2*a));
			k=-(D/(2*b));
			a=sqrt(z/a);
			b=sqrt(z/b);
			printf("\nCoordinates of center(%f,%f)\n",h,k);
			fprintf(fp1,"\nCoordinates of center(%f,%f)\n",h,k);
			if(b>a){
				swap=b;
				b=a;
				a=swap;
				c=sqrt(a*a-b*b);
				printf("Axis is parallel to Y-axis\nCoordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of minor axis B(%f,%f)B`(%f,%f)\necentricity=%f",h,k+c,h,k-c,h,k+a,h,k-a,h+b,k,h-b,k,c/a);
				printf("Length of latus rectum=%f units",((2*b*b)/a));
				fprintf(fp1,"Axis is parallel to Y-axis\nCoordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of minor axis B(%f,%f)B`(%f,%f)\necentricity=%f",h,k+c,h,k-c,h,k+a,h,k-a,h+b,k,h-b,k,c/a);
				fprintf(fp1,"Length of latus rectum=%f units",((2*b*b)/a));
			}
			else{
				c=sqrt(a*a-b*b);
				printf("Axis is parallel to X-axis\nCoordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of minor axis B(%f,%f)B`(%f,%f)\necentricity=%f",h+c,k,h-c,k,h+a,k,h-a,k,h,k+b,h,k-b,c/a);
				printf("\nLength of latus rectum=%f units",((2*b*b)/a));
				fprintf(fp1,"Axis is parallel to X-axis\nCoordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of minor axis B(%f,%f)B`(%f,%f)\necentricity=%f",h+c,k,h-c,k,h+a,k,h-a,k,h,k+b,h,k-b,c/a);
				fprintf(fp1,"\nLength of latus rectum=%f units",((2*b*b)/a));
			}
		}
}	
	if(no==8){
		system("cls");
		int choice;
		printf("To solve the equation of hyperbola and find its coordinates of transvrse axis,conjugate axis and focii\nEcentricity and length of latus rectum.");
		printf("\n1.ax^2-by^2=c\t(where c is positive)\n2.ay^2-bx^2=c\t(where c is positive)\n3.ax^2-by^2+Cx+Dy+F=0\n4.by^2-ax^2+Cx+Dy+F=0");
		scanf("%d",&choice);
		float a,b,c,e,l,z,C,D,F,h,k,swap;
		if(choice==1){
		printf("\nax^2-by^2=c\nEnter the values of a,b,c in respective order\n");
		scanf("%f%f%f",&a,&b,&c);
		a=sqrt(c/a);
		b=sqrt(c/b);
		hyperbola(&a,&b,&c);
		printf("Vertex/Transverse axis is along x axis\nCoordinates of Vertices(%f,0),(%f,0)\nCoordinates of conjugate xis(0,%f),(0,%f)",a,-a,b,-b);
		printf("\nCordinates of focii(%f,0),(%f,0)\n",c,-c);
		fprintf(fp1,"Vertex/Transverse axis is along x axis\nCoordinates of Vertices(%f,0),(%f,0)\nCoordinates of conjugate xis(0,%f),(0,%f)",a,-a,b,-b);
		fprintf(fp1,"\nCordinates of focii(%f,0),(%f,0)\n",c,-c);
	}
	    if(choice==2){
	    printf("\nay^2-bx^2=c\nEnter the values of a,b,c in respective order\n");
		scanf("%f%f%f",&a,&b,&c);
		a=sqrt(c/a);
		b=sqrt(c/b);
		hyperbola(&a,&b,&c);
		printf("Vertex/Transverse axis is along y axis\nCoordinates of Vertices(0,%f),(0,%f)\nCoordinates of conjugate axis(%f,0),(%f,0)",b,-b,a,-a);
		printf("\nCordinates of focii(0,%f),(0,%f)\n",c,-c);
		fprintf(fp1,"Vertex/Transverse axis is along y axis\nCoordinates of Vertices(0,%f),(0,%f)\nCoordinates of conjugate axis(%f,0),(%f,0)",b,-b,a,-a);
		fprintf(fp1,"\nCordinates of focii(0,%f),(0,%f)\n",c,-c);
	}
	   if(choice==3){
	   	printf("ax^2-by^2+Cx+Dy+F=0   Enter the values of a,b(without negative sign),C,D,F in respective order\n");
	   	scanf("%f%f%f%f%f",&a,&b,&C,&D,&F);
			z=-F+a*(C/(2*a))*(C/(2*a))-(b*(D/(2*b))*(D/(2*b)));
			if(z<0){
			hyperbola2(a,b,C,D,F,z);
			}
			else{
			hyperbola1(a,b,C,D,F,z);
			}
	   }
	   if(choice==4){
	   	printf("by^2-ax^2+Cx+Dy+F=0   Enter the values of b,a(without negative sign),C,D,F in respective order\n");
	   	scanf("%f%f%f%f%f",&b,&a,&C,&D,&F);
			z=-F-a*(C/(2*a))*(C/(2*a))+(b*(D/(2*b))*(D/(2*b)));
			if(z<0){
			hyperbola4(a,b,C,D,F,z);
			}
			else{
			hyperbola3(a,b,C,D,F,z);
			}
	   }
}
if(no==9){
	system("cls");
	printf("To solve the equation of parabola and find its coordinates of focus and vertex\nlength of latus rectum.");
	printf("\n1.y^2=4ax\n2.x^2=4ay\n3.y^2+By+Cx+F=0\n4.x^2+Bx+Cy+F=0");
	int choice;
	float a,h,k,B,C,F;
	scanf("%d",&choice);
	if(choice==1){
		printf("Enter the term with x:");
		scanf("%f",&a);
		printf("Vertex is at origin V(%d,%d) and axis is along x-axis\nCoordinate of Focus S(%f,%f)\nLength of latus rectum(|4a|)= %f units",0,0,a/4,0,a<0?-a:a);
		fprintf(fp1,"Vertex is at origin V(%d,%d) and axis is along x-axis\nCoordinate of Focus S(%f,%f)\nLength of latus rectum(|4a|)= %f units",0,0,a/4,0,a<0?-a:a);}
	if(choice==2){
		printf("Enter the term with y:");
		scanf("%f",&a);
		printf("Vertex is at origin V(%d,%d) and axis is along y-axis\nCoordinate of Focus S(%f,%f)\nLength of latus rectum(|4a|)= %f units",0,0,0,a/4,a<0?-a:a);
	    fprintf(fp1,"Vertex is at origin V(%d,%d) and axis is along y-axis\nCoordinate of Focus S(%f,%f)\nLength of latus rectum(|4a|)= %f units",0,0,0,a/4,a<0?-a:a);
		}
	if(choice==3){
	printf("Enter B,C,F in respective order from equation y^2+By+Cx+F=0:");
	scanf("%f %f %f",&B,&C,&F);
	h=(B*B)/(4*C)-F/C;
	k=-B/2;
	a=-C/4;
	printf("Axis of Parabola is parallel to X-Axis\nCoordinates of the Vertex V(%f,%f)\nCoordinates of FOCUS(%f,%f)\nLength of Latus Rectum=%f units\nAxis of parabola y-%.2f=0",h,k,h+a,k,a<0?-4*a:4*a,k);
	fprintf(fp1,"Axis of Parabola is parallel to X-Axis\nCoordinates of the Vertex V(%f,%f)\nCoordinates of FOCUS(%f,%f)\nLength of Latus Rectum=%f units\nAxis of parabola y-%.2f=0",h,k,h+a,k,a<0?-4*a:4*a,k);
	}
	if(choice==4){
	printf("Enter B,C,F in respective order from equation x^2+Bx+Cy+F=0:");
	scanf("%f %f %f",&B,&C,&F);
	h=(B*B)/(4*C)-F/C;
	k=-B/2;
	a=-C/4;
	printf("Axis of Parabola is parallel to Y-Axis\nCoordinates of the Vertex V(%f,%f)\nCoordinates of FOCUS(%f,%f)\nLength of Latus Rectum=%f units\nAxis of parabola x-%.2f=0",h,k,h,k+a,a<0?-4*a:4*a,h);
	fprintf(fp1,"Axis of Parabola is parallel to Y-Axis\nCoordinates of the Vertex V(%f,%f)\nCoordinates of FOCUS(%f,%f)\nLength of Latus Rectum=%f units\nAxis of parabola x-%.2f=0",h,k,h,k+a,a<0?-4*a:4*a,h);
	}
}
if(no==10){
	return 0;
}
int choice;
	printf("\n1.Return to previous menu\n2.Return to main menu\nEnter your choice:");
	scanf("%d",&choice);
	if(choice==1)
	section1();
	else
	return 0; 
}
int section3(){
	system("cls");
	int i;
	char c,str[200];
	fdisplay_03=fopen("myfile.txt","r");
	fscanf(fdisplay_03," %[^\0]",str);
	printf ("%s",str); 
    fclose(fdisplay_03);
		scanf("%d",&i);
		if(i==4){
			system("cls");
			float j;
			printf("Enter angle to convert in degrees:");
			scanf("%f",&j);
			j=(j*180)/PI;
			printf("angle in degree=%f",j);
			fprintf(fp1,"angle in degree=%f",j);
			int choice;
			printf("\n1.Return to previous menu\n2.Return to main menu\n3.Enter your choice:");
			scanf("%d",&choice);
			if(choice==1)
			section3();
			else
			return 0;
		}
		else if(i==1){
			system("cls");
			int i;
			float area=0;
	        fdisplay_05=fopen("area.txt","r");
	        fscanf(fdisplay_05," %[^\0]",str);
	        printf ("%s",str); 
            fclose(fdisplay_05);
			scanf("%d",&i);
			switch(i){
				case 1:{
					int x1,y1,x2,y2,x3,y3;
			    	printf("Enter vertix (x1,y1):");
				    scanf("%d%d",&x1,&y1);
				    printf("\nEnter vertix (x2,y2):");
				    scanf("%d%d",&x2,&y2);
				    printf("\nEnter vertix (x3,y3):");
				    scanf("%d%d",&x3,&y3);
			    	area=0.5*((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1));
			    	break;}
			    case 2:{
			    	float a,b,c;
			    	printf("Enter length of a and b sides and angle of <c in degree:");
			    	scanf("%f%f%f",&a,&b,&c);
			    	if(c>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
			    	c=(c*PI)/180;
			    	area=0.5*(a*b*sin(c));
					break;}
				case 3:{
					float a,b,c,d;
					int num;
					printf("\nWhat do you have?\n1.2 angles <b and <c and side a(different angles and different side)\n2.2 angles <b and <a and side a(2 angles and 1 same side)\nEnter your choice:");
					scanf("%d",&num);
					if(num==1){
					printf("Enter length of  side 'a' and enter both the angles <b and <c in degree: ");
					scanf("%f%f%f",&a,&b,&c);
					if(c>=180||b>=180||c+b>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
					d=180-(b+c);
					area=0.5*a*a*sin(c*PI/180)*sin(b*PI/180)/sin(d*PI/180);}
					if(num==2){
					printf("Enter length of  side 'a' and enter both the angles <a and <b in degree: ");
					scanf("%f%f%f",&a,&b,&c);
					if(c>=180||b>=180||c+b>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
					d=180-(b+c);
					area=0.5*a*a*sin(c*PI/180)*sin(d*PI/180)/sin(b*PI/180);
					}
					break;}
				case 4:{
					float a,b,c,s,max;
					printf("Enter sides of all lengths:");
					scanf("%f%f%f",&a,&b,&c);
					max=a>b?(a>c?a:c):(b>c?b:c);
					if(max>a+b+c-a||max>a+b+c-b||max>a+b+c-c){
					
					printf("Invalid sides of triangle entered\n");
					fprintf(fp1,"Invalid Size of Angle entered\n");}
					else{
					s=(a+b+c)/2;
					area=sqrt(s*(s-a)*(s-b)*(s-c));}
					break;}
				case 5:{
					section3();
					break;
				}
				default:
					break;
					}
					printf("The area is %f units sq",area);
					fprintf(fp1,"The area is %f units sq",area);
					int choice;
					printf("\n1.Return to previous menu\n2.Return to main menu\nEnter your choice:");
					scanf("%d",&choice);
					if(choice==1)
					section3();
					else
					return 0;
			}
		else if(i==2){
			system("cls");
			char l;
			char str[200];
	        fdisplay_04=fopen("triangle.txt","r");
           	fscanf(fdisplay_04," %[^\0]",str);
	        printf ("%s",str); 
            fclose(fdisplay_04);
			int i,max;
			float a,b,c,ang_a=0,ang_b=0,ang_c=0;
			scanf("%d",&i);
			switch(i){
				case 1:{
					printf("Enter all the three sides the function will return all angles in degrees:");
					scanf("%f%f%f",&a,&b,&c);
					max=a>b?(a>c?a:c):(b>c?b:c);
					if(max>a+b+c-a||max>a+b+c-b||max>a+b+c-c){
					printf("Invalid sides of triangle entered as these sides doesnot constitute a triangle\n");
					fprintf(fp1,"Invalid sides of triangle entered as these sides doesnot constitute a triangle\n");
					}
					else{
					ang_a=acos((b*b+c*c-(a*a))/(2*b*c))*180/PI;
					ang_b=acos((a*a+c*c-(b*b))/(2*a*c))*180/PI;
					ang_c=acos((b*b+a*a-(c*c))/(2*b*a))*180/PI;}
					break;
				}
				case 2:{
					int num;
					printf("\nwhat do you have?\n1.2 sides a,b and angle <a\n2.2 sides a,b and angle <b\n3.2 sides a,b and angle <c\n");
					scanf("%d",&num);
					if(num==1){
						printf("Enter the 2 sides a,b and angle <a in degrees:");
					    scanf("%f%f%f",&a,&b,&ang_a);
					    if(ang_a>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
					    ang_b=asin(b*sin(ang_a*PI/180)/a)*180/PI;
					    ang_c=180-(ang_a+ang_b);
					    c=sqrt(a*a+b*b-(2*b*a*cos(ang_c*PI/180)));
					}
					else if(num==2){
						printf("Enter the 2 sides a,b and angle <b in degrees:");
					    scanf("%f%f%f",&a,&b,&ang_b);
					    if(ang_b>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
					    ang_a=asin(a*sin(ang_b*PI/180)/b)*180/PI;
					    ang_c=180-(ang_a+ang_b);
					    c=sqrt(a*a+b*b-(2*b*a*cos(ang_c*PI/180)));
					}
					else if(num==3){
					printf("Enter the 2 sides a,b and angle <c in degrees:");
					scanf("%f%f%f",&a,&b,&ang_c);
					if(ang_c>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
					c=sqrt(a*a+b*b-(2*b*a*cos(ang_c*PI/180)));
					ang_a=acos((b*b+c*c-(a*a))/(2*b*c))*180/PI;
					ang_b=acos((a*a+c*c-(b*b))/(2*a*c))*180/PI;}
					break;
				}
				case 3:{
					int num;
					printf("\nwhat do you have?\n1.2 angles <a,<b and side c\n2.2 angles <b,<a and side a\n");
					scanf("%d",&num);
					if(num==1){
					printf("Enter two angles <a and <b and side c:");
					scanf("%f%f%f",&ang_a,&ang_b,&c);
					if(ang_a>=180||ang_b>=180||ang_a+ang_b>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
					ang_c=180-(ang_a+ang_b);
					a=c*sin(ang_a*PI/180)/sin(ang_c*PI/180);
					b=c*sin(ang_b*PI/180)/sin(ang_c*PI/180);}
					else if(num==2){
					printf("Enter two angles <a and <b and side a:");
					scanf("%f%f%f",&ang_a,&ang_b,&a);
					if(ang_a>=180||ang_b>=180||ang_a+ang_b>=180){
			    		printf("Invalid Size of Angle entered\n");
			    		fprintf(fp1,"Invalid Size of Angle entered\n");
			    		break;
					}
					ang_c=180-(ang_a+ang_b);
					c=a*sin(ang_c*PI/180)/sin(ang_a*PI/180);
					b=a*sin(ang_b*PI/180)/sin(ang_a*PI/180);
					}
					break;
				}
				case 4:{
					printf("Enter all the vertices");
					int x1,y1,x2,y2,x3,y3;
					printf("\nEnter vertix (x1,y1):");
				    scanf("%d%d",&x1,&y1);
				    printf("\nEnter vertix (x2,y2):");
				    scanf("%d%d",&x2,&y2);
				    printf("\nEnter vertix (x3,y3):");
				    scanf("%d%d",&x3,&y3);
					c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
					b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
					a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
					if(a==0||b==0||c==0){
					fprintf(fp1,"Invalid vertices of triangle\n");
					printf("Invalid vertices of triangle\n");}
					else{
					ang_a=acos((b*b+c*c-(a*a))/(2*b*c))*180/PI;
					ang_b=acos((a*a+c*c-(b*b))/(2*a*c))*180/PI;
					ang_c=acos((b*b+a*a-(c*c))/(2*b*a))*180/PI;}
					break;
				}
				case 5:{
					section3();
					break;
				}
				default:
					break;
			}
			printf("side a =%f  angle a=%f\nside b=%f  angle b=%f\nside c=%f  angle c=%f",a,ang_a,b,ang_b,c,ang_c);
			fprintf(fp1,"side a =%f  angle a=%f\nside b=%f  angle b=%f\nside c=%f  angle c=%f",a,ang_a,b,ang_b,c,ang_c);
			int choice;
			printf("\n1.Return to previous menu\n2.Return to main menu\nEnter your choice:");
			scanf("%d",&choice);
			if(choice==1)
			section3();
			else
			return 0;
		}
		else if(i==3){
			system("cls");
			float a,b,c,R,r,s,delta,max;
			printf("Enter length of all sides(a,b,c) to find the circum radius and In radius of triangle:");
			scanf("%f%f%f",&a,&b,&c);
			max=a>b?(a>c?a:c):(b>c?b:c);
			if(max>a+b+c-a||max>a+b+c-b||max>a+b+c-c){
			fprintf(fp1,"Invalid sides of triangle entered\n");
			printf("Invalid sides of triangle entered\n");}
			else{
			s=(a+b+c)/2;
			delta=sqrt(s*(s-a)*(s-b)*(s-c));
			R=(a*b*c)/(4*delta);
			r=delta/s;}
			printf("Circum radius of triangle R=%f units\nIn radius of triangle r=%f units\n",R,r);
			fprintf(fp1,"Circum radius of triangle R=%f units\nIn radius of triangle r=%f units\n",R,r);
			int choice;
			printf("\n1.Return to previous menu\n2.Return to main menu\nEnter your choice:");
			scanf("%d",&choice);
			if(choice==1)
			section3();
			else
			return 0;
		}
		else if(i==5){
			system("cls");
			float x1,y1,x2,y2,x3,y3;
			float G1=0,G2=0,a,b,c,I1=0,I2=0;
			printf("Enter vertix (x1,y1):");
			scanf("%f%f",&x1,&y1);
		    printf("\nEnter vertix (x2,y2):");
			scanf("%f%f",&x2,&y2);
		    printf("\nEnter vertix (x3,y3):");
		    scanf("%f%f",&x3,&y3);
			c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
			a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
			if(a==0||b==0||c==0){
			fprintf(fp1,"Invalid vertices of triangle\n");
			printf("Invalid vertices of triangle\n");}
			else{
			G1=(x1+x2+x3)/3.0;
			G2=(y1+y2+y3)/3.0;
			I1=(a*x1+b*x2+c*x3)/(a+b+c);
			I2=(a*y1+b*y2+c*y3)/(a+b+c);}
			printf("Centroid(%f,%f)\nIncentre(%f,%f)\n",G1,G2,I1,I2);
			fprintf(fp1,"Centroid(%f,%f)\nIncentre(%f,%f)\n",G1,G2,I1,I2);
			int choice;
			printf("\n1.Return to previous menu\n2.Return to main menu\n3.Enter your choice:");
			scanf("%d",&choice);
			if(choice==1)
			section3();
			else
			return 0;
		}
		else if(i==6)
		   return 0;
		else
		printf("in valid number pressed");
}
int section2(){
	system("cls");
	int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX],I,J,K,M,N,R,S,CH,i,j,ch,determinant=0,transpose[100][100];
	printf("\n1.Addition of two matrices\n2.Subtraction of two matrices\n3.Multiplication of two matrices\n4.For single matrix operations\n5.Return to main menu\nEnter your choice:");
    scanf("%d",&CH);
    switch(CH){
    case 1 :
    {
    system("cls");
    printf("ENTER THE SIZE OF A MATRIX (M X N) : \n");
    printf("ENTER VALUE FOR M (2 OR 3 ONLY) :");
    scanf("%d",&M);
    printf("ENTER VALUE FOR N (2 OR 3 ONLY) :");
    scanf("%d",&N);
    printf("\nENTER THE SIZE OF B MATRIX (R X S) : \n");
    printf("ENTER VALUE FOR R (2 OR 3 ONLY) :");
    scanf("%d",&R);
    printf("ENTER VALUE FOR S (2 OR 3 ONLY) :");
    scanf("%d",&S);
       if(M==R && N==S)
       {
        printf("ENTER %d X %d MATRIX A VALUES\n",M,N);
        printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
        for(I=0;I<M;I++)
        {
            for(J=0;J<N;J++)
            {
                scanf("%d,",&A[I][J]);
            }
        }
        printf("ENTER %d X %d MATRIX B VALUES\n",R,S);
        	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
        for(I=0;I<R;I++)
        {
            for(J=0;J<S;J++)
            {
                scanf("%d,",&B[I][J]);
            }
        }
        for(I=0;I<M;I++)
        {
            for(J=0;J<N;J++)
            {
                C[I][J]=A[I][J]+B[I][J];
            }
        }
        printf("\nRESULT %d X %d MATRIX C VALUES ARE :\n",M,N);
        for(I=0;I<M;I++)
        {
            for(J=0;J<N;J++)
            {
                printf("%d\t",C[I][J]);
                fprintf(fp1,"%d\t",C[I][J]);
            }
            printf("\n");
            fprintf(fp1,"\n");
        }
       }
       else
       {
        printf("\nERROR : CONDITION FOR ADDITION");
        printf(" MATRICES IS NOT SATISFIED!");
        fprintf(fp1,"\nERROR : CONDITION FOR ADDITION");
        fprintf(fp1," MATRICES IS NOT SATISFIED!");
       }
    break;
    }
    case 2 :
    {
    system("cls");
    printf("ENTER THE SIZE OF A MATRIX (M X N) : \n");
     printf("ENTER VALUE FOR M (2 OR 3 ONLY) :");
     scanf("%d",&M);
     printf("ENTER VALUE FOR N (2 OR 3 ONLY) :");
     scanf("%d",&N);
     printf("\nENTER THE SIZE OF B MATRIX (R X S) : \n");
     printf("ENTER VALUE FOR R (2 OR 3 ONLY) :");
     scanf("%d",&R);
     printf("ENTER VALUE FOR S (2 OR 3 ONLY) :");
     scanf("%d",&S);
       if(M==R && N==S)
       {
        printf("ENTER %d X %d MATRIX A VALUES\n",M,N);
        	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
        for(I=0;I<M;I++)
        {
            for(J=0;J<N;J++)
            {
                scanf("%d,",&A[I][J]);
            }
        }
        printf("ENTER %d X %d MATRIX B VALUES\n",R,S);
        	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
        for(I=0;I<R;I++)
        {
            for(J=0;J<S;J++)
            {
                scanf("%d,",&B[I][J]);
            }
        }
        for(I=0;I<M;I++)
        {
            for(J=0;J<N;J++)
            {
                C[I][J]=A[I][J]-B[I][J];
            }
        }
        printf("\nRESULT %d X %d MATRIX C VALUES ARE :\n",M,N);
        fprintf(fp1,"\nRESULT %d X %d MATRIX C VALUES ARE :\n",M,N);
        for(I=0;I<M;I++)
        {
            for(J=0;J<N;J++)
            {
                printf("%d\t",C[I][J]);
                fprintf(fp1,"%d\t",C[I][J]);
            }
            printf("\n");
            fprintf(fp1,"\n");
        }
       }
       else
       {
        printf("\nERROR : CONDITION FOR SUBTRACTION");
        printf(" MATRICES IS NOT SATISFIED!");
        fprintf(fp1,"\nERROR : CONDITION FOR SUBTRACTION");
        fprintf(fp1," MATRICES IS NOT SATISFIED!");
       }
    break;
    }
    case 3 :
    {
    	system("cls");
    printf("ENTER THE SIZE OF A MATRIX (M X N) : \n");
     printf("ENTER VALUE FOR M (2 OR 3 ONLY) :");
     scanf("%d",&M);
     printf("ENTER VALUE FOR N (2 OR 3 ONLY) :");
     scanf("%d",&N);
     printf("\nENTER THE SIZE OF B MATRIX (R X S) : \n");
     printf("ENTER VALUE FOR R (2 OR 3 ONLY) :");
     scanf("%d",&R);
     printf("ENTER VALUE FOR S (2 OR 3 ONLY) :");
     scanf("%d",&S);
       if(N==R)
       {
        printf("ENTER %d X %d MATRIX A VALUES\n",M,N);
        	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
        for(I=0;I<M;I++)
        {
            for(J=0;J<N;J++)
            {
                scanf("%d,",&A[I][J]);
            }
        }
        printf("ENTER %d X %d MATRIX B VALUES\n",R,S);
        	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
        for(I=0;I<R;I++)
        {
            for(J=0;J<S;J++)
            {
                scanf("%d,",&B[I][J]);
            }
        }
        for(I=0;I<M;I++)
        {
            for(J=0;J<S;J++)
            {
                C[I][J]=0;
                for(K=0;K<R;K++)
                {
                    C[I][J]=C[I][J]+A[I][K]*B[K][J];
                }
            }
        }
        printf("\nRESULT %d X %d MATRIX C VALUES ARE :\n",M,S);
        fprintf(fp1,"\nRESULT %d X %d MATRIX C VALUES ARE :\n",M,S);
        for(I=0;I<M;I++)
        {
            for(J=0;J<S;J++)
            {
                printf("%d\t",C[I][J]);
                fprintf(fp1,"%d\t",C[I][J]);
            }
            printf("\n");
            fprintf(fp1,"\n");
        }
       }
       else
       {
        printf("\nERROR : CONDITION FOR MULTIPLICATION");
        printf(" MATRICES IS NOT SATISFIED!");
        fprintf(fp1,"\nERROR : CONDITION FOR MULTIPLICATION");
        fprintf(fp1," MATRICES IS NOT SATISFIED!");
       }
    break;
    }
    case 4:
    {
    	system("cls");
    	int rows,col;
       printf("\nFOR SINGLE MATRIX OPERTAIONS PLEASE FOLLOW");
       	printf("\nPlease Enter Number Of Rows Matrix(2 OR 3 ONLY)");
       	scanf("%d",&rows);
       	printf("please enter number of columns of matrix(2 OR 3 ONLY)");
       	scanf("%d",&col);
		   printf("\n1.DETERMINANT\n2.INVERSE\n3.TRANSPOSE\n4.ADJOINT\n5.MATRIX SINGULAR OR NOT\n6.Return to previous menu\nEnter your choice:");
			scanf("%d",&ch);
		switch(ch){
			case 1:{
				if(rows==2&&col==2){
					 det2by2();
				}
				else if(rows==3&&col==3){
					det3by3();
				}
				break;
			}
			case 2:{
				if(rows==2&&col==2){
					inverse2x2();
				}
				else if(rows==3&&col==3){
					inverse3x3();
				}
				
				break;
			}
			case 3:{
				if(rows==2&&col==2){
					transpose2x2();
				}
				else if(rows==3&&col==3){
					transpose3x3();
				}
				break;
			}
			case 4:{
				if(rows==2&&col==2){
					adjoint2x2();
				}
				else if(rows==3&&col==3){
					adjoint3x3();
				}
				
				break;
			}
			case 5: {
				if(rows==2&&col==2){
					singular2x2();
				}
				else if(rows==3&&col==3){
					singular3x3();
				}
				break;
			}
			case 6:{
				section2();
				return 0;
			}
		}
		break;
	}
	case 5:{
		return 0;
	}
    }
    int choice;
	printf("\n1.Return to previous menu\n2.Return to main menu\n3.Enter your choice:");
	scanf("%d",&choice);
	if(choice==1)
	section2();
	else
	return 0; 
}

int det3by3(){
	int i,j,k,A[50][50],determinant=0;
	printf("Enter elements of matrix row wise:\n");
	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++)
            		scanf("%d,", &A[i][j]);}
     		for(i = 0; i < 3; i++)
		determinant = determinant + (A[0][i] * (A[1][(i+1)%3] * A[2][(i+2)%3] - A[1][(i+2)%3] * A[2][(i+1)%3]));
		printf("DETERMINANT OF 3X3 MATRIX IS : %d",determinant);
		fprintf(fp1,"DETERMINANT OF 3X3 MATRIX IS : %d",determinant);
}
int det2by2(){
   int arr[2][2], i, j;
    long determinant;
    printf("\n\nEnter the 4 elements of the array\n");
    	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
    for(i = 0; i < 2; i++)
    	for(j = 0; j < 2; j++)
    	scanf("%d,", &arr[i][j]);
    	printf("\n\nThe entered matrix is: \n\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d\t", arr[i][j]);}
        printf("\n"); }
    determinant = arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1];
    printf("\n\nDterminant of 2x2 matrix is : %d - %d =  %d", arr[0][0]*arr[1][1], arr[1][0]*arr[0][1], determinant);
    fprintf(fp1,"\n\nDterminant of 2x2 matrix is : %d - %d =  %d", arr[0][0]*arr[1][1], arr[1][0]*arr[0][1], determinant);
}
int inverse3x3(){
	int i,j,A[50][50];
	int determinant=0;
	printf("Enter elements of matrix row wise:\n");
		printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++)
            	scanf("%d,", &A[i][j]);}
     		for(i = 0; i < 3; i++)
	        	determinant = determinant + (A[0][i] * (A[1][(i+1)%3] * A[2][(i+2)%3] - A[1][(i+2)%3] * A[2][(i+1)%3]));
		 	for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
				
				printf("%.2f\t",((A[(j+1)%3][(i+1)%3] * A[(j+2)%3][(i+2)%3]) - (A[(j+1)%3][(i+2)%3] * A[(j+2)%3][(i+1)%3]))/ determinant);
				fprintf(fp1,"%.2f\t",((A[(j+1)%3][(i+1)%3] * A[(j+2)%3][(i+2)%3]) - (A[(j+1)%3][(i+2)%3] * A[(j+2)%3][(i+1)%3]))/ determinant);}
		 printf("\n");
		 fprintf(fp1,"\n");
		 }
}
int inverse2x2(){
	int arr[2][2], i, j,temp;
    long determinant;
    printf("\n\nEnter the 4 elements of the array\n");
    	printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
    for(i = 0; i < 2; i++)
    	for(j = 0; j < 2; j++)
    	scanf("%d,", &arr[i][j]);
    	printf("\n\nThe entered matrix is: \n\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d\t", arr[i][j]);}
        printf("\n"); }
    determinant = arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1];
    printf("\n\nDterminant of 2x2 matrix is : %d - %d =  %d", arr[0][0]*arr[1][1], arr[1][0]*arr[0][1], determinant);
    fprintf(fp1,"\n\nDterminant of 2x2 matrix is : %d - %d =  %d", arr[0][0]*arr[1][1], arr[1][0]*arr[0][1], determinant);
      temp = arr[0][0];                
    arr[0][0] = arr[1][1];
    arr[1][1] = temp;
    arr[0][1] = -arr[0][1];  
    arr[1][0] = -arr[1][0];
    for(i=0;i<2;i++){               
        for(j=0;j<2;j++)
            arr[i][j] = arr[i][j]/determinant;
    }
    printf("\n\nThe inverse of the matrix is:\n"); 
	fprintf(fp1,"\n\nThe inverse of the matrix is:\n");  
    for( i=0;i<2;i++){
        for( j=0;j<2;j++){
            printf("%f  ",arr[i][j]);
            fprintf(fp1,"%f  ",arr[i][j]);
        }
        printf("\n");
        fprintf(fp1,"\n");
    }
}
int transpose3x3(){
	int i,j,A[50][50],transpose[50][50];
	printf("\nenter the elements of matrix\n");
		printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
				for(i = 0; i < 3; i++){
					for(j = 0; j < 3; j++)
            		scanf("%d,", &A[i][j]);}
	 		 	for (i = 0; i < 3; ++i){
				   for (j = 0; j < 3; ++j) 
            		transpose[j][i] = A[i][j];
        }
    		printf("\nTranspose of the matrix:\n");
    		fprintf(fp1,"\nTranspose of the matrix:\n");
    		for (i = 0; i < 3; ++i)
        		for (j = 0; j < 3; ++j) {
            		printf("%d  ", transpose[i][j]);
            		fprintf(fp1,"%d  ", transpose[i][j]);
            if (j == 2){
                printf("\n");
                 fprintf(fp1,"\n");}
	}
}
int transpose2x2(){
	int i,j,A[50][50],transpose[50][50];
	printf("\nenter the elements of matrix\n");
		printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
				for(i = 0; i < 2; i++){
					for(j = 0; j < 2; j++)
            		scanf("%d,", &A[i][j]);}
	 		 	for (i = 0; i < 2; ++i){
				   for (j = 0; j < 2; ++j) 
            		transpose[j][i] = A[i][j];}
            		printf("\nTranspose of the matrix:\n");
            		fprintf(fp1,"\nTranspose of the matrix:\n");
    		for (i = 0; i <2; ++i){
				for (j = 0; j <2; ++j) {
            		printf("%d  ", transpose[i][j]);
            		fprintf(fp1,"%d  ", transpose[i][j]);       		
            if (j == 1){
			fprintf(fp1,"\n");
                printf("\n");}
				}}}

int adjoint2x2(){
	int arr[5][5],j,i,d,A[5][5],B1,B2,B3,B4;
	printf("\nenter the elements of matrix\n");
		printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
	for(i=0;i<2;i++)
	{ for(j=0;j<2;j++)
	  { printf("Enter an element:");
	    scanf("%d,",&arr[i][j]);
	  }
	}
	printf("\nMatrix element of A are given below\n");
	for(i=0;i<2;i++)
	{ for(j=0;j<2;j++)
	  { printf("\t%d",arr[i][j]);
	  }
	  printf("\n");
}
	  B1=arr[0][0];
	  B2=arr[0][1];
	  B3=arr[1][0];
	  B4=arr[1][1];
	  printf("\nAdjoint of matrix A =\n\t%d\t%d\n\t%d\t%d",B4,-B2,-B3,B1);
	  fprintf(fp1,"\nAdjoint of matrix A =\n\t%d\t%d\n\t%d\t%d",B4,-B2,-B3,B1);
	  d=arr[0][0]*arr[0][1]-arr[1][0]*arr[1][1];
	  printf("\nDetertiment of matrix A=%d",d);
	  fprintf(fp1,"\nDetertiment of matrix A=%d",d);
}
int adjoint3x3(){
		int arr[5][5],j,i,d,A[5][5],A1,A2,A3,A4,A5,A6,A7,A8,A9;
		printf("\nenter the elements of matrix\n");
			printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
	for(i=0;i<3;i++)
	{ for(j=0;j<3;j++)
	  { printf("Enter an element:");
	    scanf("%d,",&arr[i][j]);
	  }
	}
	printf("\nMatrix element of A are given below\n");
	for(i=0;i<3;i++)
	{ for(j=0;j<3;j++)
	  { printf("\t%d",arr[i][j]);
	  }
	  printf("\n");
}
	A1=(arr[1][1]*arr[2][2]-arr[2][1]*arr[1][2]);
	  A2=(arr[1][2]*arr[2][0]-arr[1][0]*arr[2][2]);
	  A3=(arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1]);
	  A4=(arr[0][2]*arr[2][1]-arr[0][1]*arr[2][2]);
	  A5=(arr[0][0]*arr[2][2]-arr[0][2]*arr[2][0]);
	  A6=(arr[0][1]*arr[2][0]-arr[0][0]*arr[2][1]);
	  A7=(arr[0][1]*arr[1][2]-arr[0][2]*arr[1][1]);
	  A8=(arr[0][2]*arr[1][0]-arr[0][0]*arr[1][2]);
	  A9=(arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]);
	  printf("\nAdjoint of matrix A =\n\t%d\t%d\t%d\n\t%d\t%d\t%d\n\t%d\t%d\t%d",A1,A4,A7,A2,A5,A8,A3,A6,A9);
	  fprintf(fp1,"\nAdjoint of matrix A =\n\t%d\t%d\t%d\n\t%d\t%d\t%d\n\t%d\t%d\t%d",A1,A4,A7,A2,A5,A8,A3,A6,A9);
	  d=arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])-arr[0][1]*(arr[1][0]*arr[2][2]-arr[2][0]*arr[1][2])+arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
	  printf("\nDetertiment of matrix A=%d",d);
	  fprintf(fp1,"\nDetertiment of matrix A=%d",d);
}
int singular3x3(){
	int i,j,k,A[50][50],determinant=0;
	printf("Enter elements of matrix row wise:\n");
		printf("\nTo shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter\n");
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++)
            		scanf("%d,", &A[i][j]);}
     		for(i = 0; i < 3; i++)
		determinant = determinant + (A[0][i] * (A[1][(i+1)%3] * A[2][(i+2)%3] - A[1][(i+2)%3] * A[2][(i+1)%3]));
		printf("DETERMINANT OF 3X3 MATRIX IS : %d",determinant);
		fprintf(fp1,"\nDETERMINANT OF 3X3 MATRIX IS : %d",determinant);
		if(determinant==0){
			printf("\nmatrix is singular ");
			fprintf(fp1,"\nmatrix is singular ");}
			else{
			fprintf(fp1,"\nmatrix is non singular ");
			printf("\nmatrix is not singular");}
}
int singular2x2(){
	 int arr[2][2], i, j;
    long determinant;
    printf("\n\nEnter the 4 elements of the array\n");
    	printf("To shift to next Element in matrix Row use Comma(,) And to shift to next element in column press Enter");
    for(i = 0; i < 2; i++)
    	for(j = 0; j < 2; j++)
    	scanf("%d,", &arr[i][j]);
    	printf("\n\nThe entered matrix is: \n\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d\t", arr[i][j]);}
        printf("\n"); }
    determinant = arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1];
    printf("\n\nDterminant of 2x2 matrix is : %d - %d =  %d", arr[0][0]*arr[1][1], arr[1][0]*arr[0][1], determinant);
    fprintf(fp1,"\n\nDterminant of 2x2 matrix is : %d - %d =  %d", arr[0][0]*arr[1][1], arr[1][0]*arr[0][1], determinant);
    if(determinant==0){
    	printf("\n matrix is singular");
		fprintf(fp1,"\n matrix is singular");}
    	else{
    	printf("matrix is not singular");
    	fprintf(fp1,"matrix is not singular");}
}
void ellipse(float *a,float *b,float *c){
	float e,l;
	*c=sqrt(*a*(*a)-*b*(*b));
	e=*c/(*a);
	l=2*(*b)*(*b)/(*a);
	printf("\nEcentricity=%f\nlength of latus rectum=%f units\n",e,l);
	fprintf(fp1,"\nEcentricity=%f\nlength of latus rectum=%f units\n",e,l);
}
void hyperbola(float *a,float *b,float *c){
	float e,l;
	*c=sqrt(*a*(*a)+*b*(*b));
	e=*c/(*a);
	l=2*(*b)*(*b)/(*a);
	printf("\nEcentricity=%f\nlength of latus rectum=%f units\n",e,l);
	fprintf(fp1,"\nEcentricity=%f\nlength of latus rectum=%f units\n",e,l);
}
void hyperbola1(float a,float b,float C,float D,float F,float z){
	float h,k,c;
	h=-(C/(2*a));
	k=(D/(2*b));
	a=sqrt(z/a);
	b=sqrt(z/b);
	c=sqrt(a*(a)+b*(b));
	printf("\nCoordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h+c,k,h-c,k,h+a,k,h-a,k,h,k+b,h,k-b,c/a);
	printf("\nLength of latus rectum=%f units",((2*b*b)/a));
	fprintf(fp1,"\nCoordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h+c,k,h-c,k,h+a,k,h-a,k,h,k+b,h,k-b,c/a);
	fprintf(fp1,"\nLength of latus rectum=%f units",((2*b*b)/a));
}
void hyperbola2(float a,float b,float C,float D,float F,float z){
	float h,k,c,l;
	l=a;
    z=-z;
	h=-(C/(2*a));
	k=(D/(2*b));
	a=sqrt(z/b);
	b=sqrt(z/l);
	c=sqrt(a*(a)+b*(b));
	printf("Coordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h,k+c,h,k-c,h,k+a,h,k-a,h+b,k,h-b,k,c/a);
	printf("\nLength of latus rectum=%f units",((2*b*b)/a));
	fprintf(fp1,"Coordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h,k+c,h,k-c,h,k+a,h,k-a,h+b,k,h-b,k,c/a);
	fprintf(fp1,"\nLength of latus rectum=%f units",((2*b*b)/a));
}
void hyperbola3(float a,float b,float C,float D,float F,float z){
	float h,k,c,l;
	l=a;
	h=(C/(2*a));
	k=-(D/(2*b));
	a=sqrt(z/b);
	b=sqrt(z/l);
	c=sqrt(a*(a)+b*(b));
	printf("Coordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h,k+c,h,k-c,h,k+a,h,k-a,h+b,k,h-b,k,c/a);
	printf("\nLength of latus rectum=%f units",((2*b*b)/a));
	fprintf(fp1,"Coordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h,k+c,h,k-c,h,k+a,h,k-a,h+b,k,h-b,k,c/a);
	fprintf(fp1,"\nLength of latus rectum=%f units",((2*b*b)/a));
}
void hyperbola4(float a,float b,float C,float D,float F,float z){
	float h,k,c,l;
	l=a;
	h=(C/(2*a));
	k=-(D/(2*b));
	printf("%f      %f   %f",h,k,z);
	a=sqrt(-z/a);
	b=sqrt(-z/b);
	c=sqrt(a*(a)+b*(b));
	printf("Coordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h+c,k,h-c,k,h+a,k,h-a,k,h,k+b,h,k-b,c/a);
	printf("\nLength of latus rectum=%f units",((2*b*b)/a));
	fprintf(fp1,"Coordinates of focii S(%f,%f)S`(%f,%f)\nCoordinates of vertices V(%f,%f)V`(%f,%f)\nCoordinates of conjugate axisB(%f,%f)B`(%f,%f)\nEcentricity=%f",h+c,k,h-c,k,h+a,k,h-a,k,h,k+b,h,k-b,c/a);
	fprintf(fp1,"\nLength of latus rectum=%f units",((2*b*b)/a));
}
