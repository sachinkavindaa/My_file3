#include<stdio.h>
#include<math.h>


//The dynamics between the cancer cells 
double  func_1( double x, double y, double z, double t) 
{
	 double   b   = 1 *pow( 10 , -9);
	 double   g_2 = pow(10 , 5);
     double   r_2 = 0.18; 
     double   a   = 1; 
  

	 double   var_4;
	  var_4 = x * r_2 * ( 1 - b * x ) - ((a * x * y)/(g_2 + x ));
	return var_4;
}


//The dynamics between the immune cells
double  func_2( double x, double y, double z, double t)
{
	  double   s_1 = 0;
	  double   p_1 = 0.1245;
	  double   g_1 = 2 * pow(10,7);
	  double   m_2 = 0.03;
      double   c   = 0.02; // The value of the parameter c varies according to the change conditions 
	  
	  
	  double   var_5;
	  var_5 = s_1 + c * x + ((p_1 * y * z)/(g_1 + z)) - m_2 * y ;
	return var_5;

}

//The dynamics between the cytokines
double  func_3(double x, double y, double z, double t)
{
	 double   s_2 = 0;
	 double   p_2 = 5;  
	 double   g_3 = 1000;
	 double   m_3 = 10;
	

	 double   var_6;
      var_6 = s_2 + ((p_2 * x * y)/(g_3 + x)) - m_3 * z;
	return var_6;
}


int main(){
 	
FILE *fp;
fp =fopen("My_code1.txt","w+");
if(fp==NULL)

{
printf("\n unable to open");
return 0;
}
	
		
	double   a , l, c;
	double   t_0 , x_0 , y_0 , z_0 , t_n , h , x_1 , y_1 , z_1;
    double   k_1 , k_2 , k_3 , k_4 , k , m_1 , m_2 , m_3 , m_4 , m , w_1 , w_2 , w_3 , w_4 , w;

  printf("\n");
  printf(".........Tumor Growth Modulated by Effector Cells and Cytokines.........\n");
  printf("\n");
  
  printf("...............Enter  the initial conditions...............\n");
  printf("\n");

                  
  printf("t_0 = "); //Initial value for t
  scanf("%lf",&t_0); 
  printf("x_0 = "); //Initial value for x
  scanf("%lf",&x_0); 
  printf("y_0 = "); //Initial value for y
  scanf("%lf",&y_0); 
  printf("z_0 = "); //Initial value for y
  scanf("%lf",&z_0); 
  
  printf("Enter the calculation period tn = "); 
  scanf("%lf",&t_n); 
  
  printf("Enter the number of steps l = "); 
  scanf("%lf",&l); 


//Solving mathematical models using the Runge Kutte (Fourth order) method.



//Calculating step size
  h = (t_n - t_0) / l;
                                           										                                       

  printf("\n  tn\t\t     x1\t\t   y1\t\t   z1\t\t");
  printf("\n");
  printf("............................................................\n");
  printf("\n");

  for ( a=0 ; a<l ;  a++ )
    {

      k_1 = h * ( func_1 ( (x_0) , (y_0) , (z_0) , (t_0) ) );
      m_1 = h * ( func_2 ( (x_0) , (y_0) , (z_0) , (t_0) ) );
      w_1 = h * ( func_3 ( (x_0) , (y_0) , (z_0) , (t_0) ) );
      
      k_2 = h * ( func_1 ( (x_0 + k_1/2) , (y_0 + m_1/2) , (z_0 + w_1/2) , (t_0 + h/2) ) );
      m_2 = h * ( func_2 ( (x_0 + k_1/2) , (y_0 + m_1/2) , (z_0 + w_1/2) , (t_0 + h/2) ) );
      w_2 = h * ( func_3 ( (x_0 + k_1/2) , (y_0 + m_1/2) , (z_0 + w_1/2) , (t_0 + h/2) ) );
      
      k_3 = h * ( func_1 ( (x_0 + k_2/2) , (y_0 + m_2/2) , (z_0 + w_2/2) , (t_0 + h/2) ) );
      m_3 = h * ( func_2 ( (x_0 + k_2/2) , (y_0 + m_2/2) , (z_0 + w_2/2) , (t_0 + h/2) ) );
      w_3 = h * ( func_3 ( (x_0 + k_2/2) , (y_0 + m_2/2) , (z_0 + w_2/2) , (t_0 + h/2) ) );
      
      k_4 = h * ( func_1 ( (x_0 + k_3) , (y_0 + m_3) , (z_0 + w_3) , (t_0 + h) ) );
      m_4 = h * ( func_2 ( (x_0 + k_3) , (y_0 + m_3) , (z_0 + w_3) , (t_0 + h) ) );
      w_4 = h * ( func_3 ( (x_0 + k_3) , (y_0 + m_3) , (z_0 + w_3) , (t_0 + h) ) );
      
      k  = ( k_1 + ( 2 * k_2 ) + ( 2 * k_3 ) + k_4 ) / 6;
      m  = ( m_1 + ( 2 * m_2 ) + ( 2 * m_3 ) + m_4 ) / 6;
      w  = ( w_1 + ( 2 * w_2 ) + ( 2 * w_3 ) + w_4 ) / 6;
     

      x_1 = x_0 + k;  //final answer for the var_4 equation model
      
      y_1 = y_0 + m;  //final answer for the var_5 equation model
      
      z_1 = z_0 + w;  //final answer for the var_6 equation model


      //Print the final answer of the t_0, x_1 , y_1 , z_1 

      printf(" %.8lf\t\t   %0.8lf\t\t  %0.8lf\t\t   %0.8lf\n", t_0, x_1 , y_1 , z_1 );
      
      fprintf(fp, "%0.8lf\t\t   %0.8lf\t\t  %0.8lf\t\t   %0.8lf\n ", t_0 , x_1 , y_1 , z_1 );
      
      
     t_0 = t_0 + h;

      x_0 = x_1;
      y_0 = y_1;
      z_0 = z_1;
      
      
    }


}
