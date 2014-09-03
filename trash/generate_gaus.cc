{

  TF1 *f1 = new TF1("f1","gaus");
  f1->SetParameters(1, 0, 0.1);
  f1->Draw();
  
  for (int i= 0; i < 101; i++){
    double x = -1.0 + 0.02*i;
    cout <<fixed<< x << " " << f1->Eval(x) << endl;
  }

}
