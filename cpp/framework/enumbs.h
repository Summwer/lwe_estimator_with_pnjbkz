#include "bssa.h"
#include <fplll/threadpool.h>




class EnumBS{
    public:
        //implement tours rounds of BKZ-beta-J
        struct strategy{
            int beta; 
            int jump;
            int tours;
        };
        struct blocksize_strategy{
            tuple<int,int,double,double,double> dsvp_t;
            vector<strategy> S; //pnj-BKZ strategy: 
            vector<double> l;
            pair<double,double> cum_GB_BKZ;
            pair<double,double> cum_avg_GB_BKZ;
            pair<double,double> avg_GB; //total cost.
            double cum_pr; //cumulated probability 
            double slope;
            pair<double,double> min_GB;
            pair<double,double> GB_nopr;
            bool leaf; // to determine whether this stratey could be further improved.
        };

        vector<blocksize_strategy> BS; //key: beta;  value: blocksize_strategy
        vector<vector<blocksize_strategy>> tmpBS; //key: beta;  value: blocksize_strategy
        
        BKZJSim* sim;
        COST* cost;
        vector<double> l0;
        bool verification = false;
        
        thread_pool::thread_pool threadpool;
        Params* params;
        double pre_pr = 0.;
        
        EnumBS(Params* params,int d){
            sim = new BKZJSim(params,d);
            cost = new COST(params);
            this->params = params;
            cout<<"enumbs min_G_prec = "<< params->min_G_prec <<endl;
        }

        void set_threads(int nr);

        void print_strategy(vector<strategy> S);
        void print_BS(vector<blocksize_strategy> BS);
        void print_bs(blocksize_strategy bs);

        int find_pos_for_dsvp(int cdsvp);
        int find_pos_for_dsvp(double dsvp);
        int binary_search_for_cdsvp(double cdsvp);
        int binary_search_for_dsvp(int dsvp);
        int binary_search_for_G2(double G2);
        int binary_search_for_G(double G);
        // int binary_search_for_slope(blocksize_strategy bs);
        int binary_search_for_G2_slope(blocksize_strategy bs);
        int binary_search_for_dsvp_slope(blocksize_strategy bs);

        pair<int,int> get_max_strategy(vector<EnumBS::strategy> S);
        bool compare_max_strategy(vector<EnumBS::strategy> S0, vector<EnumBS::strategy> S1);

        // int max_beta_in_S(vector<EnumBS::strategy> S);
        // vector<double> extract_cdsvp();
        vector<int> extract_dsvp();
        vector<double> extract_PSC();
        vector<double> extract_G2();
        // vector<pair<double,double>> extract_G2G1();
        // vector<double> extract_slope();
        // vector<double> extract_cum_pr();
        // vector<tuple<double,double,double>> extract_G2_slope_cum_pr();
        bool no_repeated_value_verification(vector<int> nums);
        bool no_repeated_value_verification(vector<double> nums);

        void BS_add(EnumBS::blocksize_strategy bs, int k); 
        // void BS_add_G2(EnumBS::blocksize_strategy bs, int k);


        bool pnjbkz_beta_loop( vector<double> &l, pair<double,double> &cum_GB_BKZ,  pair<double,double> &cum_avg_GB_BKZ,  pair<double,double> &avg_GB, double &cum_pr, int beta, int jump, tuple<int,int,double,double,double> &dsvp_t_, double &slope, pair<double,double> &GB_nopr, pair<double,double> &min_GB, bool &leaf);


        void max_tour_for_pnjbkz_beta(int k, int beta,int jump);
        // void max_tour_for_pnjbkz_beta_G2(int k, int beta,int jump);
        // pair<int,bool> max_tour_for_pnjbkz_beta_G2_backup(int k, int beta,int jump);
        void enumbs_est(vector<double> l0); //Generate strategy for enumbs

        void max_tour_for_pnjbkz_beta_in_parallel(int  beta_j_t_id_begin, vector<pair<int,int>> beta_j_tid,int k);
        
        void enumbs_est_in_parallel(vector<double> l0); //Generate strategy for enumbs in parallel
        

        // pair<double,double> strategy_verification( vector<double> l,vector<strategy> strategy);

      

};