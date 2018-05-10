//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "firmware/parameters.h"
#include "firmware/myproject.h"
#include "nnet_helpers.h"


int main(int argc, char **argv)
{
    
    input_t  data_str[IN_HEIGHT*IN_WIDTH*N_CHAN] = {0.00392156885937, 0.603921592236, 0.992156863213, 0.352941185236, 0.0, 0.0, 0.0, 0.0, 0.0, 0.54509806633, 0.992156863213, 0.745098054409, 0.00784313771874, 0.0, 0.0, 0.0, 0.0, 0.0431372560561, 0.745098054409, 0.992156863213, 0.274509817362, 0.0, 0.0, 0.0, 0.0, 0.0, 0.137254908681, 0.945098042488, 0.882352948189, 0.627451002598, 0.423529416323, 0.00392156885937, 0.0, 0.0, 0.0, 0.317647069693, 0.941176474094, 0.992156863213, 0.992156863213, 0.466666668653, 0.0, 0.0, 0.0, 0.0, 0.176470592618, 0.729411780834, 0.992156863213, 0.992156863213, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0627451017499, 0.364705890417, 0.988235294819, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.976470589638};

    result_t res_str[OUT_HEIGHT*OUT_WIDTH*N_FILT];
    for(int i=0; i<OUT_HEIGHT; i++){
	for(int j=0; j<OUT_WIDTH; j++){
	    for(int k=0; k<N_FILT; k++){
//		res_str[i][j][k]=0;
		res_str[i*OUT_WIDTH*N_FILT + j*N_FILT + k]=0;
	    }
	}
    }

    unsigned short size_in, size_out;
    myproject(data_str, res_str, size_in, size_out);

    result_t res_expected[OUT_HEIGHT*OUT_WIDTH*N_FILT] = {0.571149349213, 0.245058056898, 0.776596754789, 0.491826725192, 0.0282734036446, 0.497432035394, -0.731440126896, 0.456735980697, -0.370487630367, 0.0811160923913, 0.498784462921, -0.00178966022213, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 1.04687970877, 0.462720883079, 1.52019304037, 0.819503051229, 0.66632387042, 1.04003695864, -0.779787957668, 0.882446330972, -0.893464744091, 0.401820641942, 0.224735558033, -0.0125349983573, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 0.902743786573, 0.24730622489, 1.39311683178, 0.752578598447, 1.1647413969, 0.96261630673, 0.00230526924133, 0.946209353395, -1.08239990473, 0.794787210412, -0.534801900387, 0.254284572788, -0.129974663258, 0.095531960018, 0.0757329761982, -0.0214213663712, 0.537372652441, 0.0170038575307, 1.06692320108, 0.372042817064, 1.43391489983, 0.855602067895, 0.754285424948, 0.848806065507, -0.247355520725, 1.10587529559, -0.701065003872, 0.751396340318, -0.641312897205, 0.419155579992, -0.642057240009, 0.230588731356, 0.506766974926, -0.00139685254544, 0.604148678482, 0.0571508640423, 1.2520929575, 0.53400842566, 1.39657247066, 0.829214614816, 0.904585897923, 1.10965220351, 0.369030982256, 1.34543780703, -0.526395738125, 0.92988298554, -0.867526710033, 0.663576823659, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 0.732136055827, 0.134099286981, 1.22803282738, 0.496560049243, 1.32845795155, 0.874075037427, 1.19979757071, 1.20818416495, 0.558770164847, 1.26151661295, -0.283476173878, 0.864193839021, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 0.631972014904, 0.073878784664, 1.0464527607, 0.350103956647, 1.2716177702, 0.681069177575, 1.14246165752, 1.14882199187, 0.324020385742, 0.720709246583, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 0.506766974926, -0.00139685254544, 0.551284328103, 0.0253678178415, 0.768632620573, 0.160153132863, 1.4095287919, 0.843129497953, 0.69235175848, 0.0864589335397};

/*    
    for(int i=0; i<OUT_HEIGHT; i++){
	for(int j=0; j<OUT_WIDTH; j++){
	    for(int k=0; k<N_FILT; k++){
		std::cout << res_str[i][j][k] << " (expected " << res_expected[i][j][k] << ", " << 100.0*((float)res_str[i][j][k]-(float)res_expected[i][j][k])/(float)res_expected[i][j][k] << " percent difference)" << std::endl;
            }
	}
    }
    //std::cout << std::endl;
    */
  
    return 0;
}
