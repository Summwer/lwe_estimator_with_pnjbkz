#include "../framework/est.h"


//params input in main function
//argv[0]: implemented file name
//argv[1]: jump value J
//argv[2]: max_loop value
//argv[3]: cost model: 1.gate model 2.practical sec model
//argv[4]: maximal dimension in enumeration
//argv[5]: threads number
//argv[6]: practical_pump_d4f
//argv[7]: start beta value.
//argv[8]: est model in dsvp_prediction for last pump
int main(int argc,char **argv){
    Params* params = new Params; //J, gap, J_gap, cost_model, verbose,
    params->J = atoi(argv[1]); 
    params->max_loop = atoi(argv[2]);
    params->cost_model = atoi(argv[3]); //sec model;
    params->max_dim = atoi(argv[4]);
    params->threads = atoi(argv[5]);
    params->practical_pump_d4f = atoi(argv[6]);
    
    // params->enumbs_min_G = false;
    params->beta_start = atoi(argv[7]);
    // params->est_model = atoi(argv[8]);
    if(atoi(argv[9]) == 1)
        params->worst_case = true;
    else   
        params->worst_case = false;
    params->enumbs_slope_prec = 1e-6;
    params->min_G_prec = 1e-3;
    params->enumbs_G_prec = 1e-3;
    if(params->cost_model == 1){
        if(atoi(argv[8]) == 1)
            params->list_decoding = "agps20"; //"matzov22"
        if(atoi(argv[8]) == 2)
            params->list_decoding = "matzov22"; //"matzov22"
        // params->print_Gcums = true;
    }
    if(atoi(argv[8]) == 1)
        params->max_RAM = 30; //1.5T = 43.58, 500G = 38.9

    params->dsvp_predict_param = 1;
    
    // params->beta_start = 10;
    // params->compute_jub = 2;
    // params->verbose = true;

    // params->succ_prob = 0.85;

    // params->debug = true;
    // params->verbose = true;

    // params->enumbs_min_G = false;
    // params->min_G_prec = 2;s

    vector<pair<int,double>> lwes;



    // lwes = { 
    //     {40, 0.025}, {40,0.030}, {40,0.035}, {40,0.040}, {40,0.045},  {40,0.050}, 
    //     {45, 0.020}, {45, 0.025}, {45,0.030}, {45,0.035}, {45,0.040}, {45,0.045},  {45,0.050}, 
    //     {50, 0.015}, {50, 0.020}, 
    //     {60, 0.010}, {80, 0.005}, {45,0.030}, {50,0.025},{55,0.020},{60,0.015}, {65,0.010}, {70,0.010}, {90,0.005}, {40,0.045}, {45,0.035}, {50,0.030}, {55,0.025}, {60,0.020}, {65,0.015}, {75,0.010}, {95,0.005}};

    // lwes = { {40,0.020}, {40,0.025}, {40,0.030}, {40,0.035}, {40,0.040}, 
    //         {45,0.015}, {45,0.020}, {45,0.025}, {45,0.030}, {45,0.035}, {45,0.040}, 
    //         {50,0.010}, {50,0.015}, {50,0.020}, {50,0.025}, {50,0.030}, {50,0.035}, {50,0.040}, 
    //         {55,0.010}, {55,0.015},{55,0.020}, {55,0.025}, {55,0.030}, {55,0.035}, {55,0.040}, 
    //         {60,0.010}, {60,0.015}, {60,0.020}, {60,0.025}, {60,0.030}, {60,0.035}, {60,0.040}, 
    //         {65,0.010}, {65,0.015},  {65,0.020}, {65,0.025}, {65,0.030}, {65,0.035}, {65,0.040},
    //          {70,0.010}, {70,0.015},{70,0.020}, {70,0.025}, {70,0.030}, {70,0.035}, {70,0.040}, 
    //         {75,0.005}, {75,0.010}, {75,0.015}, {75,0.020}, {75,0.025}, {75,0.030}, {75,0.035}, {75,0.040}, 
    //         {80,0.005}, {80,0.010}, {80,0.015},{80,0.020}, {80,0.025}, {80,0.030}, {80,0.035}, {80,0.040}, {90,0.005}, {100,0.005}};

    lwes = { {100,0.005}};

    // lwes = { {60,0.005}, {70,0.005}, {85,0.005}, {95,0.005}};


    // lwes = {{85,0.005}, {90,0.010}, {95,0.010}, {100,0.010}, {75,0.025}, {75,0.030}, {75,0.035}};

    // lwes = {{95,0.005}};

    // lwes = { {40, 0.025}, {40,0.030}, {45, 0.020}, {50, 0.015},  {80, 0.005}};

    for(int i = 0; i < int(lwes.size());i++){
        int n = lwes[i].first;
        double alpha  = lwes[i].second;
        lwechal_est(n, alpha, params);
    }

    
    // //solve_lwechal_est
    // lwes =  {{45,0.030}, {50, 0.025}, {55, 0.020}, {60, 0.015}, {85, 0.005}, {90, 0.005}};
    // for(int i = 0; i < int(lwes.size());i++){
    //     int n = lwes[i].first;
    //     double alpha  = lwes[i].second;
    //     lwechal_est(n, alpha, params);
    // }

 
    
    return 1;
}
