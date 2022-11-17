function p = multigauss(x, cent, sigm)
  n = size(x, 2);

  will_div_by_pi = (2*pi)^(n/2);
  will_div_by_determ = det(sigm)^0.5;
  will_exp_left_term = (x-cent)/2;
  will_exp_pinv = pinv(sigm);
  will_exp_right_term = (x-cent)';
  will_div_by = will_div_by_pi * will_div_by_determ;
  will_exp_by = - will_exp_left_term * will_exp_pinv * will_exp_right_term;
  left_term = 1/will_div_by;
  right_term = e^will_exp_by;
  p = left_term * right_term;

  if isinf(p),
    p = sign(p);
  endif
end
