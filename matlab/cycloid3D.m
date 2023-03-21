
clear

P_s=[2;3;1];%起始点
P_e=[4;7;6];%目标点
%最高点
P_top=[(P_s(1)+P_e(1))/2; (P_s(2)+P_e(2))/2; (P_s(3)+P_e(3))/2+10];%摆线和贝塞尔曲线最高点

t=2;%摆动花费2s
%上升，平移，下降各段所占时间比例
% k1=0.4;
% k2=0.1;
% k3=0.4;
k1=0.5;
k2=0;
k3=0.5;
%-------------------摆线----------------------
t_mod=0;%归一化时间
for t_swing=0:0.02:t
    
    t_mod=t_swing/t;
    [P_des_x,Pd_des_x,a_des_x] =cal_cycloid_pva(P_s(1),P_e(1),t_mod);
    [P_des_y,Pd_des_y,a_des_y] =cal_cycloid_pva(P_s(2),P_e(2),t_mod);
    
    %上升
    if(t_swing<k1*t&&t_swing>=0)
        t_mod=t_swing/ (k1*t);
        [P_des_z,Pd_des_z,a_des_z] =cal_cycloid_pva(P_s(3),P_top(3),t_mod);
        %平移
    elseif(t_swing<(1-k3)*t&&t_swing>=k1)
        t_mod=(t_swing-(1-k3)*t) / (k3*t);
        [P_des_z,Pd_des_z,a_des_z] =cal_cycloid_pva(P_top(3),P_top(3),t_mod);
        %下降
    elseif(t_swing>=(1-k3)*t)
        t_mod=(t_swing-(1-k3)*t) / (k3*t);
        [P_des_z,Pd_des_z,a_des_z] =cal_cycloid_pva(P_top(3),P_e(3),t_mod);
    end
    
    %     plot(t_swing,P_des_x,'k:o')
    scatter3(P_des_x,P_des_y,P_des_z,'k')
    hold on
end

%-------------------贝塞尔曲线----------------------
P_top(3)=P_top(3)+8;%贝塞尔的最高点实际上是达不到的，为了好看，加个增量
for t=0:0.02:1%这里为了省事，就直接归一化了，所以不是t=0:0.02:t_total
    
    p_d(1)=(t^2-2*t+1)*P_s(1)+(-2*t^2+2*t)*P_top(1)+t^2*P_e(1);
    p_d(2)=(t^2-2*t+1)*P_s(2)+(-2*t^2+2*t)*P_top(2)+t^2*P_e(2);
    p_d(3)=(t^2-2*t+1)*P_s(3)+(-2*t^2+2*t)*P_top(3)+t^2*P_e(3);
    
    scatter3(p_d(1),p_d(2),p_d(3),'k')
    %     plot(p_d(2))
    % scatter3(pd_d(1),0,0,'k')
    hold on
end



