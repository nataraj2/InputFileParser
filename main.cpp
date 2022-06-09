#include <AMReX_ParmParse.H>
#include <AMReX_ParallelDescriptor.H>

using namespace amrex;

int main (int argc, char* argv[])
{
	amrex::Initialize(argc,argv);
	{
        ParmParse pp;
		
		std::cout << "\n";
		std::cout << "Reading input file " << argv[1] << "\n";

		if (pp.contains("FLOW_CASE")){
			std::string flow_case;
			pp.get("FLOW_CASE", flow_case);
			std::cout << "Flow case: " << flow_case << "\n";
		}

		if (pp.contains("RESTART")){
			std::string restart;
			pp.get("RESTART", restart);
			std::cout << "Restart: " << restart << "\n";
		}

		if (pp.contains("file_count")){
			int file_count;
			pp.query("file_count",file_count);
			std::cout << "file_count: " << file_count << "\n";
		}
		
		if (pp.contains("t_end")){
		 	double t_end;
			pp.get("t_end",t_end);
			std::cout << "t_end: " << t_end << "\n";
		}

		if (pp.contains("space_order")){
			int space_order;
			pp.query("space_order",space_order);
			std::cout << "space_order: " << space_order << "\n";
		}


		if (pp.contains("Nlevel")){
			int nlevel;
        	pp.query("Nlevel",nlevel);
			std::cout << "Nlevel: " << nlevel << "\n";
		}

		if(pp.contains("Ngrid")){
            std::vector<double> ngrid;
			pp.getarr("Ngrid", ngrid);
			int count= pp.countval("Ngrid");
			std::cout << "Ngrid: ";
			for(int i=0; i< count; i++){
				std::cout << ngrid[i] << " ";
			}
			std::cout << "\n";
		}

		if (pp.contains("MAX_ND")){
			int max_nd;
        	pp.query("MAX_ND",max_nd);
			std::cout << "MAX_ND: " << max_nd << "\n";
		}

		if (pp.contains("Ndim")){
			int ndim;
        	pp.query("Ndim",ndim);
			std::cout << "Ndim: " << ndim<< "\n";
		}

		if(pp.contains("decomp")){
            std::vector<double> decomp;
			pp.getarr("decomp", decomp);
			int count= pp.countval("decomp");
			std::cout << "decomp: ";
			for(int i=0; i< count; i++){
				std::cout << decomp[i] << " ";
			}
			std::cout << "\n";
		}



		if(pp.contains("GRID_PERIODICITY")){
			int nperiodicity = pp.countval("GRID_PERIODICITY");
			std::string nm;
			std::cout << "Grid periodicity: " ;
			for (int i = 0; i < nperiodicity ; i++){
            	pp.get("GRID_PERIODICITY", nm, i);
				std::cout << nm << " " ;
			}
			std::cout << "\n";
		}

		if(pp.contains("OVERLAP_PERIODIC")){
			int count = pp.countval("OVERLAP_PERIODIC");
			std::string nm;
			std::cout << "Overlap periodic: " ;
			for (int i = 0; i < count; i++){
            	pp.get("OVERLAP_PERIODIC", nm, i);
				std::cout << nm << " " ;
			}
			std::cout << "\n";
		}

		if(pp.contains("PERIODIC_LENGTH")){
			std::vector<double>periodic_length;
			std::cout << "PERIODIC_LENGTH: " ;
        	pp.getarr("PERIODIC_LENGTH", periodic_length);
			std::cout << periodic_length[0] << " " << periodic_length[1] << " " << periodic_length[2] << " " << periodic_length[3] << "\n";
		}

		if (pp.contains("OVERSET_GRIDS")){
			std::string overset_grids;
			pp.get("OVERSET_GRIDS", overset_grids);
			std::cout << "Overset grids: " << overset_grids << "\n";
		}

		if (pp.contains("INTERP_INTERFACE_TREATMENT")){
			std::string interp;
			pp.get("INTERP_INTERFACE_TREATMENT", interp);
			std::cout << "INTERP_INTERFACE_TREATMENT: " << interp << "\n";
		}

		if (pp.contains("METRIC_IDENTITY_TERMS")){
			std::string metric;
			pp.get("METRIC_IDENTITY_TERMS", metric);
			std::cout << "METRIC_IDENTITY_TERMS: " << metric << "\n";
		}

		if (pp.contains("FIXED_TIMESTEP")){
			std::string fixed_dt;
			pp.get("FIXED_TIMESTEP", fixed_dt);
			std::cout << "FIXED_TIMESTEP: " << fixed_dt<< "\n";
		}
		if (pp.contains("DT")){
			double dt;
			pp.get("DT", dt);
			std::cout << "DT: " << dt << "\n";
		}

		if (pp.contains("Re")){
			double Re;
			pp.get("Re", Re);
			std::cout << "Re: " << Re << "\n";
		}

		if (pp.contains("Pr")){
			double Pr;
			pp.get("Pr", Pr);
			std::cout << "Pr: " << Pr << "\n";
		}

		if (pp.contains("x_0")){
			double x_0;
			pp.get("x_0", x_0);
			std::cout << "x_0: " << x_0 << "\n";
		}

		if (pp.contains("y_0")){
			double y_0;
			pp.get("y_0", y_0);
			std::cout << "y_0: " << y_0 << "\n";
		}

		if (pp.contains("epsilon")){
			double epsilon;
			pp.get("epsilon", epsilon);
			std::cout << "epsilon: " << epsilon << "\n";
		}

		if (pp.contains("gamma_c")){
			double gamma_c;
			pp.get("gamma_c", gamma_c);
			std::cout << "gamma_c: " << gamma_c << "\n";
		}

		if (pp.contains("scale_f")){
			double scale_f;
			pp.get("scale_f", scale_f);
			std::cout << "scale_f: " << scale_f << "\n";
		}

		if (pp.contains("u_vel")){
			double u_vel;
			pp.get("u_vel", u_vel);
			std::cout << "u_vel: " << u_vel<< "\n";
		}

		if (pp.contains("Twall")){
			double Twall;
			pp.get("Twall", Twall);
			std::cout << "Twall: " << Twall << "\n";
		}

		if (pp.contains("u_inf")){
			double u_inf;
			pp.get("u_inf", u_inf);
			std::cout << "u_inf: " << u_inf << "\n";
		}

		if (pp.contains("scale_y")){
			double scale_y;
			pp.get("scale_y", scale_y);
			std::cout << "scale_y: " << scale_y << "\n";
		}
	}

}
