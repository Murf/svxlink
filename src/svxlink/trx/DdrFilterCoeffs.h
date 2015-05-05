/**
@file	 DdrFilterCoeffs.h
@brief   Filter coefficients for the DDR receiver
@author  Tobias Blomberg / SM0SVX
@date	 2015-05-04

\verbatim
SvxLink - A Multi Purpose Voice Services System for Ham Radio Use
Copyright (C) 2003-2015 Tobias Blomberg / SM0SVX

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\endverbatim
*/

#ifndef DDR_FILTER_COEFFS_INCLUDED
#define DDR_FILTER_COEFFS_INCLUDED


/****************************************************************************
 *
 * System Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Project Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Forward declarations
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Namespace
 *
 ****************************************************************************/

//namespace MyNameSpace
//{


/****************************************************************************
 *
 * Forward declarations of classes inside of the declared namespace
 *
 ****************************************************************************/

  

/****************************************************************************
 *
 * Defines & typedefs
 *
 ****************************************************************************/

#define FILTER_COEFF(name, coeffs...) \
  static const float name[] = { \
    coeffs \
  }; \
  static const int name ## _cnt = sizeof(name) / sizeof(*name);


/****************************************************************************
 *
 * Exported Global Variables
 *
 ****************************************************************************/

/**
 * fs=2400000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 400000/(fs/2) 1];
 * b=firpm(12,f,a);
 *
 * Lowpass filter of order 12 for first stage decimation from 2400kHz to 800kHz
 * sampling frequency. Below -50dB over 400kHz.
 */
FILTER_COEFF(coeff_dec_2400k_800k,
  0.0077055710085996,
  0.0231099825172581,
  0.0491033915373070,
  0.0827979875546905,
  0.1172425796413652,
  0.1432359886614141,
  0.1529234854517300,
  0.1432359886614141,
  0.1172425796413652,
  0.0827979875546905,
  0.0491033915373070,
  0.0231099825172581,
  0.0077055710085996
)

/**
 * fs=800000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 80000/(fs/2) 1];
 * b=firpm(30,f,a);
 *
 * Lowpass filter of order 30 for second stage decimation from 800kHz to 160kHz
 * sampling frequency. Below -50dB over 80kHz.
 */
FILTER_COEFF(coeff_dec_800k_160k,
  -0.0029997236277028,
  -0.0043861913900128,
  -0.0065590186109396,
  -0.0082920929936370,
  -0.0087502813117280,
  -0.0070008145790774,
  -0.0021775940281952,
  0.0063104873665492,
  0.0185989520369326,
  0.0342348393119680,
  0.0521531680677441,
  0.0707596583561849,
  0.0881384331148449,
  0.1023167472191527,
  0.1115960643590441,
  0.1148277609860070,
  0.1115960643590441,
  0.1023167472191527,
  0.0881384331148449,
  0.0707596583561849,
  0.0521531680677441,
  0.0342348393119680,
  0.0185989520369326,
  0.0063104873665492,
  -0.0021775940281952,
  -0.0070008145790774,
  -0.0087502813117280,
  -0.0082920929936370,
  -0.0065590186109396,
  -0.0043861913900128,
  -0.0029997236277028
)

/**
 * fs=160000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 16000/(fs/2) 1];
 * b=firpm(69,f,a);
 *
 * Lowpass filter of order 69 for third stage decimation from 160kHz to 32kHz
 * sampling frequency. Below -50dB over 16kHz.
 */
FILTER_COEFF(coeff_dec_160k_32k,
  -0.0021897935693675,
  -0.0014627396578915,
  -0.0013556525689907,
  -0.0007392088237726,
  0.0003574441355289,
  0.0017246039253812,
  0.0029895055896823,
  0.0037044482910084,
  0.0034725915191305,
  0.0020872049160927,
  -0.0003267103977320,
  -0.0032962979217630,
  -0.0060432956930122,
  -0.0076661105137475,
  -0.0073849727874053,
  -0.0048159145195665,
  -0.0001754973036671,
  0.0056460528670540,
  0.0111958136705557,
  0.0147666247087154,
  0.0148298059278710,
  0.0105161290387843,
  0.0020030328211424,
  -0.0092988333174977,
  -0.0208538093298570,
  -0.0294084509371543,
  -0.0316449887034609,
  -0.0249466889575552,
  -0.0080967911710057,
  0.0182565357679944,
  0.0515079450201972,
  0.0874215550152374,
  0.1208397653529333,
  0.1466281173863568,
  0.1606670688526116,
  0.1606670688526116,
  0.1466281173863568,
  0.1208397653529333,
  0.0874215550152374,
  0.0515079450201972,
  0.0182565357679944,
  -0.0080967911710057,
  -0.0249466889575552,
  -0.0316449887034609,
  -0.0294084509371543,
  -0.0208538093298570,
  -0.0092988333174977,
  0.0020030328211424,
  0.0105161290387843,
  0.0148298059278710,
  0.0147666247087154,
  0.0111958136705557,
  0.0056460528670540,
  -0.0001754973036671,
  -0.0048159145195665,
  -0.0073849727874053,
  -0.0076661105137475,
  -0.0060432956930122,
  -0.0032962979217630,
  -0.0003267103977320,
  0.0020872049160927,
  0.0034725915191305,
  0.0037044482910084,
  0.0029895055896823,
  0.0017246039253812,
  0.0003574441355289,
  -0.0007392088237726,
  -0.0013556525689907,
  -0.0014627396578915,
  -0.0021897935693675
)

/**
 * fs=960000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 96000/(fs/2) 1];
 * b=firpm(30,f,a);
 *
 * Lowpass filter of order 30 for first stage decimation from 960kHz to 192kHz
 * sampling frequency. Below -50dB over 96kHz.
 */
FILTER_COEFF(coeff_dec_960k_192k,
  -0.0028713422063345,
  -0.0041769139545598,
  -0.0062171808745743,
  -0.0078031238748803,
  -0.0081233271798609,
  -0.0062743621398142,
  -0.0014205292313401,
  0.0070048711105898,
  0.0191247988093941,
  0.0344897867015570,
  0.0520570673062483,
  0.0702711557447386,
  0.0872655777710594,
  0.1011208091483218,
  0.1101849356054080,
  0.1133410547020278,
  0.1101849356054080,
  0.1011208091483218,
  0.0872655777710594,
  0.0702711557447386,
  0.0520570673062483,
  0.0344897867015570,
  0.0191247988093941,
  0.0070048711105898,
  -0.0014205292313401,
  -0.0062743621398142,
  -0.0081233271798609,
  -0.0078031238748803,
  -0.0062171808745743,
  -0.0041769139545598,
  -0.0028713422063345
)

/**
 * fs=192000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 16000/(fs/2) 1];
 * b=firpm(83,f,a);
 *
 * Lowpass filter of order 83 for second stage decimation from 192kHz to 32kHz
 * sampling frequency. Below -50dB over 16kHz.
 */
FILTER_COEFF(coeff_dec_192k_32k,
  -0.0018908004875791,
  -0.0014088046526025,
  -0.0010323279150753,
  -0.0011609937805184,
  -0.0002616260421106,
  0.0002282613874497,
  0.0014794737163843,
  0.0021208611663994,
  0.0030372993243376,
  0.0030011893771900,
  0.0027937120905529,
  0.0014962726557786,
  -0.0000026511430646,
  -0.0022129339849578,
  -0.0040935849190142,
  -0.0058404676355097,
  -0.0064472699433756,
  -0.0061207976418120,
  -0.0042173681807972,
  -0.0012991336407301,
  0.0026759149088455,
  0.0066958942487303,
  0.0103205964042610,
  0.0123978773268841,
  0.0125150704574251,
  0.0099739187608554,
  0.0050138881239198,
  -0.0021145533182887,
  -0.0102288336524600,
  -0.0181423359949556,
  -0.0240730300262369,
  -0.0265609078833171,
  -0.0241108160478653,
  -0.0159913513331595,
  -0.0019343883009423,
  0.0173321075924516,
  0.0404780715637686,
  0.0653782990983535,
  0.0896308725182227,
  0.1106366920921416,
  0.1261268044110260,
  0.1343340191429704,
  0.1343340191429704,
  0.1261268044110260,
  0.1106366920921416,
  0.0896308725182227,
  0.0653782990983535,
  0.0404780715637686,
  0.0173321075924516,
  -0.0019343883009423,
  -0.0159913513331595,
  -0.0241108160478653,
  -0.0265609078833171,
  -0.0240730300262369,
  -0.0181423359949556,
  -0.0102288336524600,
  -0.0021145533182887,
  0.0050138881239198,
  0.0099739187608554,
  0.0125150704574251,
  0.0123978773268841,
  0.0103205964042610,
  0.0066958942487303,
  0.0026759149088455,
  -0.0012991336407301,
  -0.0042173681807972,
  -0.0061207976418120,
  -0.0064472699433756,
  -0.0058404676355097,
  -0.0040935849190142,
  -0.0022129339849578,
  -0.0000026511430646,
  0.0014962726557786,
  0.0027937120905529,
  0.0030011893771900,
  0.0030372993243376,
  0.0021208611663994,
  0.0014794737163843,
  0.0002282613874497,
  -0.0002616260421106,
  -0.0011609937805184,
  -0.0010323279150753,
  -0.0014088046526025,
  -0.0018908004875791
)

/**
 * fs=192000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 32000/(fs/2) 1];
 * b=firpm(24,f,a);
 *
 * Lowpass filter of order 24 for second stage decimation from 192kHz to 64kHz
 * sampling frequency. Below -50dB over 32kHz.
 */
FILTER_COEFF(coeff_dec_192k_64k,
  0.0031540431521627,
  0.0051378158557058,
  0.0048140778412027,
  -0.0009654829873843,
  -0.0124005132227600,
  -0.0248322507830750,
  -0.0289525722662525,
  -0.0143798504318640,
  0.0245506757440186,
  0.0838527245395222,
  0.1491061174236354,
  0.2001446431453300,
  0.2194604978120209,
  0.2001446431453300,
  0.1491061174236354,
  0.0838527245395222,
  0.0245506757440186,
  -0.0143798504318640,
  -0.0289525722662525,
  -0.0248322507830750,
  -0.0124005132227600,
  -0.0009654829873843,
  0.0048140778412027,
  0.0051378158557058,
  0.0031540431521627
)

/**
 * fs=64000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 16000/(fs/2) 1];
 * b=firpm(28,f,a);
 *
 * Lowpass filter of order 28 for third stage decimation from 64kHz to 32kHz
 * sampling frequency. Below -50dB over 16kHz.
 */
FILTER_COEFF(coeff_dec_64k_32k,
  -0.0021501279583193,
  -0.0040430950754044,
  0.0029835459944940,
  0.0089796779827107,
  0.0024317826798201,
  -0.0152141568444195,
  -0.0158319898412721,
  0.0141893791720496,
  0.0381917625792782,
  0.0047927983228653,
  -0.0643719956719470,
  -0.0622271764136555,
  0.0857677721956512,
  0.3020049518487149,
  0.4059585000445893,
  0.3020049518487149,
  0.0857677721956512,
  -0.0622271764136555,
  -0.0643719956719470,
  0.0047927983228653,
  0.0381917625792782,
  0.0141893791720496,
  -0.0158319898412721,
  -0.0152141568444195,
  0.0024317826798201,
  0.0089796779827107,
  0.0029835459944940,
  -0.0040430950754044,
  -0.0021501279583193
)

/**
 * fs=32000;
 * a=[1 1 0 0];
 * f=[0 5000/(fs/2) 8000/(fs/2) 1];
 * b=firpm(28,f,a);
 *
 * Lowpass filter of order 28 for fourth stage decimation from 32kHz to 16kHz
 * sampling frequency. Below -50dB over 8kHz.
 */
FILTER_COEFF(coeff_dec_32k_16k,
  -0.0021501279583193,
  -0.0040430950754044,
  0.0029835459944940,
  0.0089796779827107,
  0.0024317826798201,
  -0.0152141568444195,
  -0.0158319898412721,
  0.0141893791720496,
  0.0381917625792782,
  0.0047927983228653,
  -0.0643719956719470,
  -0.0622271764136555,
  0.0857677721956512,
  0.3020049518487149,
  0.4059585000445893,
  0.3020049518487149,
  0.0857677721956512,
  -0.0622271764136555,
  -0.0643719956719470,
  0.0047927983228653,
  0.0381917625792782,
  0.0141893791720496,
  -0.0158319898412721,
  -0.0152141568444195,
  0.0024317826798201,
  0.0089796779827107,
  0.0029835459944940,
  -0.0040430950754044,
  -0.0021501279583193
)

/**
 * fs=192000;
 * a=[1 1 0 0];
 * f=[0 5000/(fs/2) 24000/(fs/2) 1];
 * b=firpm(24,f,a);
 *
 * Lowpass filter of order 24 for second stage decimation from 192kHz to 48kHz
 * sampling frequency. Below -50dB over 24kHz.
 */
FILTER_COEFF(coeff_dec_192k_48k,
  -0.0040502147520988,
  -0.0072609069449002,
  -0.0112037915378169,
  -0.0134935256903211,
  -0.0117224887444940,
  -0.0035514301475168,
  0.0124767984524734,
  0.0361987559362321,
  0.0654529075825642,
  0.0962502666343449,
  0.1235320832535051,
  0.1423342164566462,
  0.1490457432547853,
  0.1423342164566462,
  0.1235320832535051,
  0.0962502666343449,
  0.0654529075825642,
  0.0361987559362321,
  0.0124767984524734,
  -0.0035514301475168,
  -0.0117224887444940,
  -0.0134935256903211,
  -0.0112037915378169,
  -0.0072609069449002,
  -0.0040502147520988
)

/**
 * fs=48000;
 * a=[1 1 0 0];
 * f=[0 5000/(fs/2) 8000/(fs/2) 1];
 * b=firpm(42,f,a);
 *
 * Lowpass filter of order 42 for second stage decimation from 48kHz to 16kHz
 * sampling frequency. Below -50dB over 8kHz.
 */
FILTER_COEFF(coeff_dec_48k_16k,
  -0.0014095656083768,
  -0.0033446547619698,
  -0.0010368158000897,
  0.0014956412176013,
  0.0053590003107099,
  0.0058980898139176,
  0.0016320747440760,
  -0.0063721569864832,
  -0.0125298356440212,
  -0.0106470023912062,
  0.0012584104815158,
  0.0172704863658967,
  0.0254956614237699,
  0.0155605107031659,
  -0.0122481244878525,
  -0.0428992486953069,
  -0.0520035474963219,
  -0.0193237750178281,
  0.0571044072688417,
  0.1555035354575194,
  0.2383783348077489,
  0.2707390686931801,
  0.2383783348077489,
  0.1555035354575194,
  0.0571044072688417,
  -0.0193237750178281,
  -0.0520035474963219,
  -0.0428992486953069,
  -0.0122481244878525,
  0.0155605107031659,
  0.0254956614237699,
  0.0172704863658967,
  0.0012584104815158,
  -0.0106470023912062,
  -0.0125298356440212,
  -0.0063721569864832,
  0.0016320747440760,
  0.0058980898139176,
  0.0053590003107099,
  0.0014956412176013,
  -0.0010368158000897,
  -0.0033446547619698,
  -0.0014095656083768
)

/**
 * fs=32000;
 * a=[1 1 0 0];
 * f=[0 10000/(fs/2) 12500/(fs/2) 1];
 * b=firpm(36,f,a);
 *
 * Lowpass filter of order 36 for channel filter to create a channel that start
 * falling off at 20kHz bandwidth and at -50dB over 25kHz bandwidth.
 * Constructed for FM.
 */
FILTER_COEFF(coeff_25k_channel,
  0.0018190280178772,
  -0.0001854258281459,
  -0.0026004079079537,
  0.0050124282883767,
  -0.0033904910252379,
  -0.0033654025130130,
  0.0107364194566141,
  -0.0105940602340494,
  -0.0013915192812513,
  0.0187499316486295,
  -0.0256014795146846,
  0.0087872427705669,
  0.0270948318689248,
  -0.0552753147954016,
  0.0408445337783302,
  0.0335140955922284,
  -0.1488062351383988,
  0.2545729546201279,
  0.7025906394915605,
  0.2545729546201279,
  -0.1488062351383988,
  0.0335140955922284,
  0.0408445337783302,
  -0.0552753147954016,
  0.0270948318689248,
  0.0087872427705669,
  -0.0256014795146846,
  0.0187499316486295,
  -0.0013915192812513,
  -0.0105940602340494,
  0.0107364194566141,
  -0.0033654025130130,
  -0.0033904910252379,
  0.0050124282883767,
  -0.0026004079079537,
  -0.0001854258281459,
  0.0018190280178772
)

/**
 * fs=16000;
 * a=[1 1 0 0];
 * f=[0 5000/(fs/2) 6250/(fs/2) 1];
 * b=firpm(36,f,a);
 *
 * Lowpass filter of order 36 for channel filter to create a channel that start
 * falling off at 10kHz bandwidth and at -50dB over 12.5kHz bandwidth.
 * Constructed for narrow FM and AM.
 */
FILTER_COEFF(coeff_12k5_channel,
  0.0018190280178772,
  -0.0001854258281459,
  -0.0026004079079537,
  0.0050124282883767,
  -0.0033904910252379,
  -0.0033654025130130,
  0.0107364194566141,
  -0.0105940602340494,
  -0.0013915192812513,
  0.0187499316486295,
  -0.0256014795146846,
  0.0087872427705669,
  0.0270948318689248,
  -0.0552753147954016,
  0.0408445337783302,
  0.0335140955922284,
  -0.1488062351383988,
  0.2545729546201279,
  0.7025906394915605,
  0.2545729546201279,
  -0.1488062351383988,
  0.0335140955922284,
  0.0408445337783302,
  -0.0552753147954016,
  0.0270948318689248,
  0.0087872427705669,
  -0.0256014795146846,
  0.0187499316486295,
  -0.0013915192812513,
  -0.0105940602340494,
  0.0107364194566141,
  -0.0033654025130130,
  -0.0033904910252379,
  0.0050124282883767,
  -0.0026004079079537,
  -0.0001854258281459,
  0.0018190280178772
)

/**
 * fs=16000;
 * a=[1 1 0 0];
 * f=[0 2600/(fs/2) 4000/(fs/2) 1];
 * b=firpm(32,f,a);
 *
 * Lowpass filter of order 32 for channel filter to create a channel that start
 * falling off at 2.6kHz bandwidth and at -50dB over 4kHz bandwidth.
 * Constructed for SSB.
 */
FILTER_COEFF(coeff_ssb_channel,
  0.0021136928439869,
  0.0020775336118770,
  -0.0033392503168020,
  -0.0056944466074802,
  0.0012986477174989,
  0.0117926503384420,
  0.0056641495955810,
  -0.0154818973323998,
  -0.0204207909678936,
  0.0113267827250988,
  0.0411160886673783,
  0.0103446260199380,
  -0.0636325829098671,
  -0.0675921412564143,
  0.0810412752797339,
  0.3042623660491556,
  0.4123175401807679,
  0.3042623660491556,
  0.0810412752797339,
  -0.0675921412564143,
  -0.0636325829098671,
  0.0103446260199380,
  0.0411160886673783,
  0.0113267827250988,
  -0.0204207909678936,
  -0.0154818973323998,
  0.0056641495955810,
  0.0117926503384420,
  0.0012986477174989,
  -0.0056944466074802,
  -0.0033392503168020,
  0.0020775336118770,
  0.0021136928439869
)

/**
 * fs=32000;
 * a=[1 1 0 0];
 * f=[0 6500/(fs/2) 8000/(fs/2) 1];
 * b=firpm(57,f,a);
 *
 * Lowpass filter of order 57 for final audio filtering and decimation from
 * 32kHz to 16kHz sampling frequency. The filter start falling off at 6500Hz.
 */
FILTER_COEFF(coeff_dec_audio_32k_16k,
  0.0002044755564088,
  0.0025162729368701,
  -0.0000373739243192,
  -0.0023823323199525,
  -0.0009174324092698,
  0.0031733626970525,
  0.0024257908780856,
  -0.0036237006402449,
  -0.0046114089386084,
  0.0033770296626382,
  0.0073898992647920,
  -0.0020191017651296,
  -0.0105102309333354,
  -0.0008742534716957,
  0.0135359367419711,
  0.0056990956333815,
  -0.0158330056196493,
  -0.0128122329209208,
  0.0165412314235204,
  0.0226120483249114,
  -0.0144736851809570,
  -0.0357965204848320,
  0.0076824090739295,
  0.0543098761642641,
  0.0082798389911014,
  -0.0854498969493825,
  -0.0509115753577537,
  0.1784581615217777,
  0.4155906562564999,
  0.4155906562564999,
  0.1784581615217777,
  -0.0509115753577537,
  -0.0854498969493825,
  0.0082798389911014,
  0.0543098761642641,
  0.0076824090739295,
  -0.0357965204848320,
  -0.0144736851809570,
  0.0226120483249114,
  0.0165412314235204,
  -0.0128122329209208,
  -0.0158330056196493,
  0.0056990956333815,
  0.0135359367419711,
  -0.0008742534716957,
  -0.0105102309333354,
  -0.0020191017651296,
  0.0073898992647920,
  0.0033770296626382,
  -0.0046114089386084,
  -0.0036237006402449,
  0.0024257908780856,
  0.0031733626970525,
  -0.0009174324092698,
  -0.0023823323199525,
  -0.0000373739243192,
  0.0025162729368701,
  0.0002044755564088
)



/****************************************************************************
 *
 * Class definitions
 *
 ****************************************************************************/



//} /* namespace */

#endif /* DDR_FILTER_COEFFS_INCLUDED */

/*
 * This file has not been truncated
 */