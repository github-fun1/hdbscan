/*
 * tester.c
 *
 *  Created on: 17 Sep 2017
 *      Author: junior
 */

#include "config.h"
#include "hdbscan/hdbscan.h"
#include "dataset.h"
#include <time.h>
float d2[] = {
		1.0,1.0,3.0,3.0,
		1.0,2.0,8.0,18.0,
		2.0,1.0,8.0,18.0,
		2.0,2.0,3.0,5.0,
		2.0,4.0,5.0,3.0,
		3.0,1.0,3.0,4.0,
		3.0,2.0,9.0,18.0,
		3.0,3.0,9.0,19.0,
		3.0,4.0,9.0,20.0,
		3.0,5.0,4.0,3.0,
		3.0,6.0,20.0,2.0,
		3.0,7.0,10.0,44.0,
		4.0,2.0,4.0,5.0,
		4.0,3.0,3.0,5.0,
		4.0,5.0,10.0,18.0,
		4.0,6.0,10.0,18.0,
		5.0,1.0,3.0,4.0,
		5.0,4.0,5.0,5.0,
		6.0,0.0,4.0,4.0,
		6.0,1.0,4.0,4.0,
		6.0,2.0,8.0,19.0,
		6.0,3.0,8.0,18.0,
		6.0,4.0,1.0,20.0};

double data[] = {
		33.43767545,64.25117848,
		33.21417899,65.10173552,
		34.2873402,66.57170405,
		31.72104043,65.82504764,
		33.88919314,64.4281437,
		33.45387321,65.71469588,
		33.65172753,65.38811408,
		33.0648241,66.11751653,
		32.8002084,68.21721569,
		33.14351067,67.30671321,
		32.68455164,65.84940263,
		34.71938353,65.56968728,
		32.40583936,64.34789329,
		33.60923947,65.98755349,
		32.35596545,66.19068221,
		32.67776212,67.1854919,
		33.92863023,66.27678254,
		33.05720912,64.81061436,
		34.46306774,64.33366761,
		32.12713463,65.31057729,
		32.30596516,67.34783558,
		32.68497202,65.15433005,
		34.76606814,65.21536683,
		34.57171608,66.68874094,
		34.22403332,66.76008944,
		32.50631792,65.46621221,
		34.98502471,66.57746854,
		32.87073672,66.20131529,
		32.37301568,63.77418022,
		33.56782612,65.91237669,
		32.93778759,66.94509413,
		33.59042542,63.54582446,
		33.05336835,66.82504644,
		33.34923695,64.11433626,
		34.77804445,65.3881255,
		33.46911514,66.67587474,
		33.89268926,64.887709,
		34.70039922,67.24786954,
		34.36125297,67.03062116,
		31.64735493,67.49251239,
		32.85706519,66.59285076,
		33.71692614,65.65225468,
		33.68530946,66.14269236,
		34.42121481,66.75193642,
		34.40076647,65.10164221,
		32.16580891,64.49097186,
		33.76747395,64.65183121,
		31.87501129,64.19156891,
		33.02597605,66.15883886,
		33.2428936,64.31490434,
		32.77417986,66.30607038,
		35.07611236,63.88516053,
		33.93977309,65.87207399,
		32.88116984,65.37874952,
		32.86238788,65.61738982,
		32.67447013,64.38834322,
		31.3443043,66.10524545,
		32.7615315,65.90947831,
		34.25155972,66.38737922,
		33.84355255,65.61133383,
		34.05355169,65.58197775,
		32.96639265,66.47327755,
		32.03515337,67.24954576,
		31.82196306,65.09737938,
		31.34092847,65.90315782,
		34.36389749,65.91847177,
		33.54263093,65.94379703,
		33.91476521,66.51445338,
		32.61986388,65.20847056,
		32.84242002,66.01437217,
		32.8129695,65.10005637,
		34.02379243,64.46273016,
		33.27048893,67.09480718,
		34.2654288,64.19860012,
		33.55786938,66.31997693,
		33.49709237,66.0797852,
		33.67511078,66.45379596,
		34.96741459,66.17681786,
		31.62049909,65.42210838,
		33.47667356,66.22079724,
		33.89948797,65.80258763,
		33.54989384,65.73966512,
		32.89391045,63.48452417,
		31.99797819,65.66243091,
		32.05985353,64.45242207,
		32.68963231,65.94670073,
		35.43056036,66.21202216,
		32.29638151,66.35777379,
		33.05645353,67.05314038,
		35.59710414,64.43861666,
		33.36907436,65.35384958,
		32.94232172,65.16159342,
		33.63729822,66.6549575,
		32.14273555,67.01046956,
		32.9401328,66.98985637,
		32.32181013,68.17057461,
		32.56114279,66.34377785,
		33.73397243,65.5759401,
		34.38263325,65.61476943,
		32.70523902,66.64801082,
		26.22789208,68.80171149,
		27.02315998,69.47915094,
		27.29388693,68.67506338,
		24.97094031,67.68926909,
		26.23197824,68.32133251,
		25.2594848,68.32493259,
		26.46105467,70.20558457,
		24.93318715,67.92639691,
		25.60262399,68.92378847,
		25.70489512,70.14080506,
		26.40578189,68.46669892,
		25.96075936,69.46114672,
		26.28434767,68.41005167,
		27.46361054,67.77986834,
		27.04197426,70.24818015,
		25.73956403,69.79277072,
		26.3652009,68.96406195,
		27.09726937,69.3118274,
		26.14702153,68.19890186,
		26.77572293,67.98655031,
		25.81729481,67.61415544,
		25.4263136,68.34159204,
		23.78714461,67.7846526,
		23.37878896,69.60887887,
		24.70572649,68.54313319,
		25.92881504,69.96049764,
		27.56035313,69.45035676,
		25.10328523,71.71311024,
		24.78004107,69.83041078,
		25.77150625,69.20829519,
		25.98558184,68.5481938,
		26.76502876,68.5544165,
		27.2593772,68.48908684,
		24.99577505,68.18412728,
		25.4990383,69.58868805,
		25.22151196,67.89053765,
		24.25239298,68.48201585,
		24.43064762,70.22773406,
		26.73230725,68.83067467,
		26.28411804,69.80815591,
		26.33885023,71.01473258,
		27.20891601,70.72628921,
		26.57088549,68.63218514,
		26.36167136,67.7213486,
		26.87794974,67.95046654,
		25.55776009,68.9906587,
		25.06246505,67.96468732,
		26.48663203,69.4699175,
		26.22585237,71.1002508,
		26.17893344,68.28511661,
		26.68470791,68.3413255,
		26.66889475,68.80865341,
		25.5152547,69.59728608,
		26.20913124,69.18088854,
		27.19924103,69.88909041,
		26.95530194,69.68559951,
		26.36454262,69.9466095,
		27.5357359,68.80263888,
		25.03789458,68.58954726,
		26.60615141,70.01859841,
		25.16624879,68.42128169,
		24.64568782,67.97247462,
		25.23155233,68.93887903,
		25.50526689,69.07726894,
		25.19664638,68.60823327,
		27.21100219,68.84418594,
		27.4141147,69.26498418,
		26.96472954,67.50761403,
		25.81631593,69.11440703,
		25.23730794,68.81393472,
		26.44672973,67.27478287,
		25.9306688,67.97172026,
		27.68963602,69.47663084,
		27.25029338,69.86051781,
		25.36241358,69.03294871,
		25.71943924,68.82261823,
		27.02980843,69.47988219,
		25.48187838,68.04027875,
		24.83222642,68.49865913,
		27.26801296,69.48669895,
		25.98920929,69.52928995,
		25.1218546,67.91295196,
		25.31912029,68.75673015,
		26.72722975,70.4234272,
		26.32337104,69.35081033,
		25.27897822,69.93492997,
		26.94148267,68.94934868,
		27.43360459,69.92677742,
		26.77659288,68.39401418,
		26.32754845,68.96920263,
		27.12129766,67.97916489,
		27.18043345,69.5658338,
		26.27863027,69.62987741,
		26.21123876,70.00265119,
		25.77476059,69.04665744,
		26.28527107,69.13849253,
		25.62577585,68.91135936,
		25.02450246,67.37104233,
		25.41227881,67.70606217,
		25.55399649,68.17763847,
		17.77957308,64.39376954,
		15.79983488,67.56236739,
		13.70317624,68.7254317,
		15.07640574,65.38372155,
		16.86553013,66.30218072,
		16.08527981,69.17453862,
		13.82322646,68.82302244,
		17.68967108,64.97536302,
		17.9727144,69.23981647,
		18.14966461,64.81429665,
		19.93520212,67.12152458,
		15.98874409,64.78844798,
		19.250549,68.88198876,
		19.10725071,64.83573483,
		15.02399546,68.15230149,
		14.23611573,69.16740237,
		19.22507009,66.06076205,
		15.2080629,68.08669478,
		16.26192648,70.12249211,
		14.67293656,65.05034601,
		14.87438317,68.9478146,
		14.33120437,64.68234791,
		16.83520108,63.97440358,
		19.1958289,66.64930592,
		13.77034616,64.46530724,
		18.74189575,64.9653732,
		17.00900793,64.11623816,
		17.26705548,64.65229758,
		12.56200047,66.48190826,
		15.96919585,63.02971934,
		16.20287952,65.21644223,
		14.72526114,65.31934067,
		16.10980997,65.95306634,
		15.05236186,67.76438305,
		17.03328885,64.3278272,
		16.44610068,65.1532088,
		14.52262429,63.65670947,
		18.56591776,64.17698602,
		18.68227234,65.59938288,
		15.53766841,63.67271282,
		18.91992618,64.06851108,
		16.17271431,63.90816723,
		16.01372956,66.24292856,
		18.67924659,65.94961068,
		12.79769829,67.00777762,
		18.94457568,67.69529835,
		18.86474358,68.80074981,
		17.52599781,66.87285713,
		19.22869378,68.99441422,
		19.74682056,67.10465371,
		15.83596723,68.125885,
		19.1571769,69.11260992,
		19.40775393,67.20088572,
		15.71772369,69.65867473,
		15.786209,67.66864746,
		16.16732181,63.99912609,
		18.16500852,66.81175633,
		12.8608407,65.97239063,
		18.92795447,67.52017158,
		16.04581836,66.90480772,
		16.38929563,63.59480842,
		14.2789366,67.40503968,
		15.7751527,68.62354995,
		12.7902207,64.79581677,
		16.48213026,67.33675263,
		13.8439298,65.59190798,
		14.95253893,67.40792608,
		16.96742558,64.99740705,
		19.37120803,66.70477387,
		19.95952636,65.38222968,
		18.18196351,67.60541698,
		12.84595114,67.96504299,
		13.13591329,68.49721892,
		15.40764029,63.52149677,
		14.09762648,66.09183174,
		18.99090168,68.38271484,
		18.93262371,64.24244698,
		16.84134851,64.79338198,
		13.16400094,65.74159409,
		16.77437576,69.42554678,
		18.39899773,68.75876967,
		13.80514871,65.05103524,
		14.36334914,68.80931501,
		14.84040281,63.85251729,
		14.88044429,63.99047993,
		13.53330395,65.40537346,
		16.48613837,69.4141661,
		17.46382059,62.96232835,
		15.50528057,63.37555309,
		16.62652719,69.79945186,
		17.51612322,68.03529083,
		14.82841596,64.93655752,
		16.1053843,70.22230741,
		13.43763947,66.44366499,
		16.1042992,68.82176822,
		17.39711692,66.52508132,
		19.00913607,67.24139886,
		14.08465386,69.17575815,
		18.45497102,67.86186777,
		17.55592948,69.29860957,
		31.07191514,78.04359376,
		30.27477622,77.64393358,
		30.17712296,77.33418084,
		30.2655254,75.46649865,
		31.07169083,78.62967235,
		32.09959207,78.08351253,
		29.83092372,77.04579336,
		30.90321805,78.03605457,
		32.02913547,77.15224114,
		30.33299489,77.01708479,
		30.85938291,76.35360088,
		29.35941176,77.17737819,
		30.93407507,77.48706812,
		29.61531762,77.57717391,
		30.09266579,78.31521309,
		29.41291193,77.71990242,
		32.27026013,76.45727829,
		30.5855278,79.87444259,
		32.86628405,76.18516524,
		28.71048664,78.20859177,
		31.62773372,77.63911159,
		30.14872157,77.54445924,
		30.12855029,78.0994797,
		30.78889702,77.16938593,
		30.64864363,76.87736758,
		29.09094407,76.59106307,
		30.93009333,78.11133484,
		31.3608881,77.67789817,
		30.16453998,76.90785764,
		30.7427035,76.64497487,
		30.91254424,78.15554713,
		30.9102776,77.70005179,
		31.39345972,78.969759,
		30.1892024,76.26294418,
		31.88793897,79.2407753,
		31.14268134,78.43383502,
		30.1574988,75.32159525,
		31.33106395,77.80370285,
		29.58968041,76.0342615,
		28.55562896,77.23537589,
		30.07272042,78.63999514,
		31.0740559,77.94452306,
		32.91274609,77.58541937,
		31.42995379,77.6718577,
		32.62551098,76.19392594,
		30.28313418,76.28160302,
		31.00643559,78.59845543,
		29.68290239,76.23103743,
		30.26721932,77.12514123,
		29.4379766,77.55452831,
		28.83508502,77.07684551,
		30.14515468,74.72159133,
		31.41509847,76.37542359,
		30.41671247,76.49591494,
		30.4713882,78.18382858,
		30.32056705,77.67566477,
		28.62174138,76.60735217,
		29.3473257,78.00519577,
		33.43855625,78.72860718,
		31.27544476,76.54025728,
		30.2234581,78.04689398,
		31.08158826,77.1621638,
		29.79744484,77.44986858,
		31.47807634,76.96096174,
		30.91837956,77.59872071,
		32.28636241,78.75760305,
		30.89904099,76.71178481,
		30.34540143,79.06656424,
		30.43985856,74.8476941,
		31.00060953,77.04337861,
		30.82850668,76.26043752,
		30.02448207,78.88109043,
		30.89840214,78.95275641,
		29.77147431,76.41639517,
		32.15599306,76.70054408,
		32.20717709,76.20380878,
		30.3325665,76.49918941,
		29.64301544,77.70358247,
		31.8062209,76.43015066,
		29.50651512,76.34939608,
		30.31883471,77.563462,
		31.92493068,74.703017,
		31.01086918,77.09864654,
		31.02693099,74.59015384,
		31.24479547,78.3481749,
		31.43733247,78.52598455,
		31.26140073,78.20432898,
		30.43783962,77.83273607,
		31.15522865,76.53092183,
		29.36208856,76.33573857,
		29.33921212,77.34659482,
		30.85566107,76.72565153,
		30.99251021,77.93888896,
		31.2777103,76.08722698,
		30.69781755,78.14923445,
		30.06517115,78.05511955,
		31.86218124,76.36342712,
		29.88974121,77.45328056,
		30.94904599,76.4288867,
		31.11565801,75.99309989,
		25.11459518,82.58188888,
		19.2408429,77.959146,
		23.25264692,76.99202229,
		20.28057228,78.07083243,
		23.50171694,78.65605794,
		21.09065694,79.36257516,
		20.41008671,78.60270516,
		22.02125629,78.28364637,
		22.25022198,77.71347099,
		24.00124342,77.46843373,
		22.49224336,79.45405019,
		21.33518956,80.47096538,
		23.48213047,75.88145247,
		21.96961,79.57424318,
		22.35468818,78.56378809,
		20.89224695,78.27590797,
		21.56926492,74.12519741,
		23.03553939,77.90247565,
		19.78939837,79.37139878,
		22.60764116,79.08125876,
		23.22431733,77.12875963,
		22.02853927,78.07661524,
		20.03693331,75.35903089,
		22.18744505,79.39823747,
		23.61821756,78.9354982,
		21.40624491,76.97016436,
		22.89477964,77.98182331,
		23.34853878,77.14152269,
		23.15878281,77.46484825,
		21.43158707,78.43589854,
		23.11787194,79.88090928,
		21.05030377,76.79150775,
		22.06291393,78.237619,
		22.39289254,78.46619301,
		23.86843164,78.4620198,
		20.04256928,76.63748077,
		19.96523058,75.77190165,
		21.29839517,76.69724735,
		23.59601833,78.30279496,
		23.2053286,77.54102474,
		22.48716983,77.28460203,
		22.76040604,76.81777228,
		21.27257775,74.88300426,
		20.57955763,79.94345926,
		24.89328364,78.64129975,
		22.27473027,76.90342514,
		22.71112188,76.81876333,
		24.17618588,77.87287817,
		21.6143882,78.74260417,
		24.35600003,77.53699913,
		19.47269657,78.10216315,
		23.33154804,78.24220152,
		23.33951979,79.59586696,
		20.87576013,77.87090503,
		24.92652923,80.31082126,
		20.94634148,78.32887783,
		23.5467413,79.14744767,
		22.08363272,81.25857735,
		23.78410072,76.1915127,
		23.21324305,78.32213449,
		22.19152969,76.13351654,
		22.12219861,77.83586109,
		21.08164396,76.43025597,
		20.31239428,76.06617582,
		23.83074402,79.84649046,
		24.57390636,76.69593077,
		20.91817884,79.83063904,
		25.00349865,81.16088814,
		19.96942565,79.27548871,
		23.43507253,74.92936687,
		23.2959204,76.01781259,
		20.94784057,77.90862548,
		23.26685645,76.30763384,
		22.51501243,77.67737886,
		22.4321776,77.51805059,
		22.83000009,76.79240942,
		19.40971678,77.56720244,
		22.97413768,78.30532019,
		22.57067507,78.12051058,
		22.16142915,79.16593578,
		18.45961894,78.92687342,
		22.94741566,77.77173651,
		23.09454726,77.68903246,
		22.9864193,77.66346679,
		21.8405903,79.57596158,
		18.69227304,77.11086772,
		25.1557967,76.51209521,
		18.71126631,77.42723157,
		23.25475424,77.09161797,
		23.24730491,74.93317816,
		21.73035594,79.47185244,
		18.22678856,76.93156183,
		19.74275678,77.54180802,
		19.44958472,79.39054743,
		23.76380735,77.29524489,
		22.43257348,79.16591584,
		21.5380754,77.49753568,
		21.7407814,79.3336489,
		20.9613116,75.10722918,
		22.8386819,79.47603878};



int main(int argc, char** argv){

	for(int i = 0; i < 1000; i++){
		printf("***********************************************************************************\n");
		//clock_t begin = clock();
		hdbscan* scan = hdbscan_init(NULL, 4, DATATYPE_DOUBLE);

		if(scan == NULL){
			printf("ERROR: Could not initialise hdbscan\n");
		} else{
			printf("SUCCESS: hdbscan fully initialised\n");
			uint w = 2;
			uint h = 500;
			clock_t begin = clock();
			int err = hdbscan_run(scan, dataset, rows, cols, TRUE);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			printf("hdbscan run Process took %f\n", time_spent);
			if(err == HDBSCAN_ERROR){
				printf("ERROR: Could not run hdbscan\n");
			} else{
				printf("SUCCESS: hdbscan clustring completed\n");

				//printf("Number total number of clusters is %d\n\n", scan->clusters->len);
				/*scan->clusterTable = hdbscan_create_cluster_table(scan->clusterLabels, scan->numPoints);
					
				GHashTableIter iter;
				gpointer key;
				gpointer value;
				g_hash_table_iter_init (&iter, scan->clusterTable);

				while (g_hash_table_iter_next (&iter, &key, &value)){
					int32_t label = *((int32_t *)key);
					IntArrayList* clusterList = (IntArrayList*)value;
					printf("%d -> [", label);
					
					for(int j = 0; j < clusterList->size; j++){
						int32_t *dpointer = int_array_list_data(clusterList, j);
						printf("%d ", *dpointer);
					}
					printf("]\n");
				}*/

				printf("\n\nCluster labels = [");
				for(uint i = 0; i < scan->numPoints; i++){
					printf("%d ", scan->clusterLabels[i]);
				}
				printf("]\n\n");
			}
		}
		hdbscan_clean(scan);
		printf("***********************************************************************************\n\n");
		exit(0);
	}

	return 0;
}
