function [P_des,v_des,a_des] = cal_cycloid_pva(p_start,p_end, t_mod)
P_des=p_start+(p_end-p_start)*( t_mod- sin(2*pi*t_mod)/(2*pi) ); 
v_des=(p_end - p_start)*(1-cos(2*pi*t_mod)  );
a_des=2*pi*sin(2*pi*t_mod)*(p_end - p_start) ;
end
