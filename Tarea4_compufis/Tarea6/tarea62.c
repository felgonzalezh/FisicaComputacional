double x_prima(int n_points, double sigma, double t, double x, double y){
  double x_p;
  x_p=sigma*1.0*(y-x);
  return x_p;
}

double y_prima(int n_points, double rho, double t, double x, double y, double z){
  double y_p;
  y_p=x*1.0*(rho-z)-y;
  return y_p;
}

double z_prima(int n_points, double beta, double t, double x, double y, double z){
  double z_p;
  z_p=(x*1.0*y)-(beta*1.0*z);
  return z_p;
}
