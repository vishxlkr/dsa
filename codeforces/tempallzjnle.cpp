    vis[bit][cx][cy] = true;
    dp_cost[bit][cx][cy] = best_c;
     p_vals[bit][cx][cy] = best_p;
    q_vals[bit][cx][cy] = best_q;
    
    return {best_c, best_p, best_q};