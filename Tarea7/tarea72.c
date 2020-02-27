
double y1_prima(int n_points, double t, double y_2){
  double y1_p;
  y1_p=y_2;
  return y1_p;
}

double y2_prima(int n_points, double k, double C, double t, double y_1, double y_2){
  double y2_p;
  y2_p=-k*(pow(y_1,-2))+C*(pow(y_1,-3));
  return y2_p;
}
