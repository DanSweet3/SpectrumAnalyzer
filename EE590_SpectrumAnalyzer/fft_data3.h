//Sawtooth sample wave, 1000 kHz
double in[2048]={
 0, -0.0000, -0.0000, -0.0000, -0.0000, -0.0001, -0.0001, -0.0001, -0.0001, -0.0002, -0.0002, -0.0002, -0.0003, -0.0003, -0.0003, -0.0004, -0.0004, -0.0005, -0.0005, -0.0005, -0.0006, -0.0006, -0.0006, -0.0007, -0.0007, -0.0008, -0.0008, -0.0008, -0.0008, -0.0009, -0.0009, -0.0009, -0.0009, -0.0009, -0.0009, -0.0009, -0.0009, -0.0009, -0.0009, -0.0009, -0.0008, -0.0008, -0.0007, -0.0007, -0.0006, -0.0006, -0.0005, -0.0004, -0.0003, -0.0002, -0.0001, -0.0000, 0.0001, 0.0002, 0.0004, 0.0005, 0.0007, 0.0009, 0.0010, 0.0012, 0.0015, 0.0017, 0.0019, 0.0021, 0.0024, 0.0027, 0.0030, 0.0033, 0.0036, 0.0039, 0.0042, 0.0046, 0.0049, 0.0053, 0.0057, 0.0061, 0.0066, 0.0070, 0.0075, 0.0079, 0.0084, 0.0089, 0.0095, 0.0100, 0.0106, 0.0112, 0.0118, 0.0124, 0.0130, 0.0137, 0.0144, 0.0151, 0.0158, 0.0165, 0.0173, 0.0181, 0.0189, 0.0197, 0.0205, 0.0214, 0.0223, 0.0232, 0.0241, -0.0245, -0.0245, -0.0244, -0.0244, -0.0243, -0.0242, -0.0242, -0.0240, -0.0239, -0.0238, -0.0236, -0.0234, -0.0232, -0.0230, -0.0228, -0.0226, -0.0223, -0.0220, -0.0217, -0.0214, -0.0210, -0.0207, -0.0203, -0.0199, -0.0195, -0.0190, -0.0186, -0.0181, -0.0176, -0.0171, -0.0165, -0.0160, -0.0154, -0.0148, -0.0141, -0.0135, -0.0128, -0.0121, -0.0113, -0.0106, -0.0098, -0.0090, -0.0082, -0.0073, -0.0065, -0.0055, -0.0046, -0.0037, -0.0027, -0.0017, -0.0006, 0.0004, 0.0015, 0.0026, 0.0038, 0.0050, 0.0062, 0.0074, 0.0086, 0.0099, 0.0113, 0.0126, 0.0140, 0.0154, 0.0168, 0.0183, 0.0198, 0.0213, 0.0229, 0.0245, 0.0261, 0.0277, 0.0294, 0.0312, 0.0329, 0.0347, 0.0365, 0.0384, 0.0402, 0.0422, 0.0441, 0.0461, 0.0481, 0.0502, 0.0523, 0.0544, 0.0566, 0.0588, 0.0610, 0.0633, 0.0656, 0.0679, 0.0703, 0.0727, 0.0752, 0.0776, 0.0802, 0.0827, 0.0853, 0.0880, 0.0907, 0.0934, -0.0954, -0.0944, -0.0934, -0.0923, -0.0913, -0.0901, -0.0890, -0.0878, -0.0866, -0.0853, -0.0841, -0.0828, -0.0814, -0.0800, -0.0786, -0.0772, -0.0757, -0.0741, -0.0726, -0.0710, -0.0694, -0.0677, -0.0660, -0.0643, -0.0625, -0.0607, -0.0588, -0.0570, -0.0550, -0.0531, -0.0511, -0.0490, -0.0470, -0.0449, -0.0427, -0.0405, -0.0383, -0.0360, -0.0337, -0.0314, -0.0290, -0.0265, -0.0241, -0.0216, -0.0190, -0.0164, -0.0138, -0.0111, -0.0084, -0.0056, -0.0028, 0.0000, 0.0029, 0.0058, 0.0088, 0.0118, 0.0148, 0.0179, 0.0211, 0.0243, 0.0275, 0.0308, 0.0341, 0.0375, 0.0409, 0.0443, 0.0478, 0.0514, 0.0550, 0.0586, 0.0623, 0.0660, 0.0698, 0.0736, 0.0775, 0.0814, 0.0853, 0.0893, 0.0934, 0.0975, 0.1016, 0.1058, 0.1101, 0.1144, 0.1187, 0.1231, 0.1275, 0.1320, 0.1365, 0.1411, 0.1458, 0.1504, 0.1552, 0.1599, 0.1648, 0.1697, 0.1746, 0.1796, 0.1846, 0.1897, 0.1948, 0.2000, 0.2052, -0.2040, -0.2012, -0.1983, -0.1954, -0.1924, -0.1894, -0.1863, -0.1831, -0.1800, -0.1768, -0.1735, -0.1702, -0.1668, -0.1634, -0.1599, -0.1564, -0.1529, -0.1493, -0.1456, -0.1419, -0.1382, -0.1344, -0.1305, -0.1266, -0.1227, -0.1187, -0.1146, -0.1105, -0.1064, -0.1022, -0.0979, -0.0936, -0.0893, -0.0849, -0.0804, -0.0759, -0.0714, -0.0668, -0.0621, -0.0574, -0.0526, -0.0478, -0.0430, -0.0380, -0.0331, -0.0280, -0.0230, -0.0178, -0.0127, -0.0074, -0.0021, 0.0032, 0.0086, 0.0141, 0.0196, 0.0251, 0.0307, 0.0364, 0.0421, 0.0479, 0.0537, 0.0596, 0.0655, 0.0715, 0.0776, 0.0837, 0.0898, 0.0960, 0.1023, 0.1086, 0.1150, 0.1214, 0.1279, 0.1345, 0.1411, 0.1477, 0.1545, 0.1612, 0.1681, 0.1749, 0.1819, 0.1889, 0.1959, 0.2030, 0.2102, 0.2174, 0.2247, 0.2321, 0.2395, 0.2469, 0.2544, 0.2620, 0.2696, 0.2773, 0.2850, 0.2928, 0.3007, 0.3086, 0.3166, 0.3246, 0.3327, 0.3409, -0.3437, -0.3383, -0.3329, -0.3275, -0.3220, -0.3164, -0.3108, -0.3051, -0.2993, -0.2936, -0.2877, -0.2818, -0.2758, -0.2698, -0.2637, -0.2576, -0.2514, -0.2452, -0.2389, -0.2325, -0.2261, -0.2196, -0.2131, -0.2065, -0.1999, -0.1931, -0.1864, -0.1796, -0.1727, -0.1657, -0.1588, -0.1517, -0.1446, -0.1374, -0.1302, -0.1229, -0.1156, -0.1082, -0.1007, -0.0932, -0.0856, -0.0780, -0.0703, -0.0625, -0.0547, -0.0468, -0.0389, -0.0309, -0.0229, -0.0147, -0.0066, 0.0017, 0.0099, 0.0183, 0.0267, 0.0352, 0.0437, 0.0523, 0.0609, 0.0696, 0.0784, 0.0872, 0.0961, 0.1050, 0.1140, 0.1231, 0.1322, 0.1414, 0.1506, 0.1599, 0.1693, 0.1787, 0.1882, 0.1977, 0.2073, 0.2169, 0.2267, 0.2364, 0.2463, 0.2562, 0.2661, 0.2762, 0.2862, 0.2964, 0.3066, 0.3168, 0.3271, 0.3375, 0.3480, 0.3585, 0.3690, 0.3796, 0.3903, 0.4010, 0.4118, 0.4227, 0.4336, 0.4446, 0.4556, 0.4667, 0.4779, 0.4891, -0.5004, -0.4921, -0.4838, -0.4754, -0.4670, -0.4584, -0.4499, -0.4412, -0.4326, -0.4238, -0.4150, -0.4061, -0.3972, -0.3882, -0.3792, -0.3701, -0.3609, -0.3517, -0.3424, -0.3330, -0.3236, -0.3141, -0.3046, -0.2950, -0.2854, -0.2757, -0.2659, -0.2561, -0.2462, -0.2362, -0.2262, -0.2162, -0.2060, -0.1958, -0.1856, -0.1753, -0.1649, -0.1545, -0.1440, -0.1335, -0.1229, -0.1122, -0.1015, -0.0907, -0.0798, -0.0689, -0.0580, -0.0469, -0.0359, -0.0247, -0.0135, -0.0023, 0.0091, 0.0204, 0.0319, 0.0434, 0.0549, 0.0665, 0.0782, 0.0899, 0.1017, 0.1136, 0.1255, 0.1375, 0.1495, 0.1616, 0.1737, 0.1859, 0.1982, 0.2105, 0.2229, 0.2353, 0.2478, 0.2604, 0.2730, 0.2856, 0.2984, 0.3111, 0.3240, 0.3369, 0.3498, 0.3628, 0.3759, 0.3890, 0.4022, 0.4155, 0.4288, 0.4421, 0.4555, 0.4690, 0.4825, 0.4961, 0.5098, 0.5235, 0.5372, 0.5510, 0.5649, 0.5788, 0.5928, 0.6068, 0.6209, 0.6350, 0.6493, -0.6481, -0.6367, -0.6253, -0.6138, -0.6022, -0.5906, -0.5789, -0.5671, -0.5553, -0.5435, -0.5315, -0.5196, -0.5075, -0.4954, -0.4833, -0.4711, -0.4588, -0.4465, -0.4341, -0.4217, -0.4092, -0.3967, -0.3840, -0.3714, -0.3587, -0.3459, -0.3331, -0.3202, -0.3072, -0.2942, -0.2812, -0.2681, -0.2549, -0.2417, -0.2284, -0.2151, -0.2017, -0.1882, -0.1747, -0.1612, -0.1476, -0.1339, -0.1202, -0.1064, -0.0926, -0.0787, -0.0648, -0.0508, -0.0368, -0.0227, -0.0085, 0.0057, 0.0199, 0.0343, 0.0486, 0.0630, 0.0775, 0.0920, 0.1066, 0.1212, 0.1359, 0.1506, 0.1654, 0.1802, 0.1951, 0.2101, 0.2251, 0.2401, 0.2552, 0.2703, 0.2855, 0.3008, 0.3161, 0.3314, 0.3468, 0.3622, 0.3777, 0.3933, 0.4089, 0.4245, 0.4402, 0.4560, 0.4718, 0.4876, 0.5035, 0.5194, 0.5354, 0.5515, 0.5675, 0.5837, 0.5998, 0.6161, 0.6324, 0.6487, 0.6650, 0.6815, 0.6979, 0.7144, 0.7310, 0.7476, 0.7642, 0.7809, -0.7915, -0.7772, -0.7628, -0.7484, -0.7339, -0.7194, -0.7049, -0.6902, -0.6756, -0.6609, -0.6461, -0.6313, -0.6164, -0.6015, -0.5866, -0.5715, -0.5565, -0.5414, -0.5262, -0.5110, -0.4958, -0.4805, -0.4651, -0.4497, -0.4343, -0.4188, -0.4032, -0.3877, -0.3720, -0.3564, -0.3406, -0.3249, -0.3090, -0.2932, -0.2773, -0.2613, -0.2453, -0.2293, -0.2132, -0.1970, -0.1809, -0.1646, -0.1484, -0.1321, -0.1157, -0.0993, -0.0829, -0.0664, -0.0498, -0.0333, -0.0167, -0.0000, 0.0167, 0.0334, 0.0502, 0.0671, 0.0839, 0.1008, 0.1178, 0.1348, 0.1518, 0.1689, 0.1860, 0.2031, 0.2203, 0.2376, 0.2548, 0.2721, 0.2895, 0.3069, 0.3243, 0.3418, 0.3593, 0.3768, 0.3944, 0.4120, 0.4297, 0.4474, 0.4651, 0.4829, 0.5007, 0.5185, 0.5364, 0.5543, 0.5723, 0.5902, 0.6083, 0.6263, 0.6444, 0.6625, 0.6807, 0.6989, 0.7171, 0.7353, 0.7536, 0.7720, 0.7903, 0.8087, 0.8271, 0.8456, 0.8641, 0.8826, 0.9012, -0.8914, -0.8746, -0.8578, -0.8409, -0.8239, -0.8069, -0.7899, -0.7729, -0.7558, -0.7387, -0.7215, -0.7043, -0.6871, -0.6698, -0.6525, -0.6351, -0.6178, -0.6003, -0.5829, -0.5654, -0.5479, -0.5303, -0.5127, -0.4951, -0.4775, -0.4598, -0.4421, -0.4243, -0.4065, -0.3887, -0.3708, -0.3530, -0.3350, -0.3171, -0.2991, -0.2811, -0.2631, -0.2450, -0.2269, -0.2088, -0.1906, -0.1724, -0.1542, -0.1359, -0.1177, -0.0993, -0.0810, -0.0626, -0.0443, -0.0258, -0.0074, 0.0111, 0.0296, 0.0481, 0.0667, 0.0853, 0.1039, 0.1225, 0.1412, 0.1598, 0.1786, 0.1973, 0.2160, 0.2348, 0.2536, 0.2725, 0.2913, 0.3102, 0.3291, 0.3480, 0.3670, 0.3859, 0.4049, 0.4239, 0.4430, 0.4620, 0.4811, 0.5002, 0.5193, 0.5384, 0.5576, 0.5768, 0.5960, 0.6152, 0.6344, 0.6537, 0.6729, 0.6922, 0.7115, 0.7309, 0.7502, 0.7696, 0.7889, 0.8083, 0.8277, 0.8472, 0.8666, 0.8861, 0.9055, 0.9250, 0.9445, 0.9640, -0.9683, -0.9497, -0.9311, -0.9124, -0.8937, -0.8751, -0.8563, -0.8376, -0.8188, -0.8001, -0.7813, -0.7624, -0.7436, -0.7247, -0.7059, -0.6870, -0.6681, -0.6491, -0.6302, -0.6112, -0.5922, -0.5732, -0.5542, -0.5351, -0.5161, -0.4970, -0.4779, -0.4588, -0.4397, -0.4205, -0.4014, -0.3822, -0.3630, -0.3438, -0.3246, -0.3054, -0.2862, -0.2669, -0.2476, -0.2284, -0.2091, -0.1898, -0.1704, -0.1511, -0.1318, -0.1124, -0.0931, -0.0737, -0.0543, -0.0349, -0.0155, 0.0039, 0.0233, 0.0427, 0.0622, 0.0816, 0.1011, 0.1205, 0.1400, 0.1595, 0.1790, 0.1985, 0.2179, 0.2375, 0.2570, 0.2765, 0.2960, 0.3155, 0.3351, 0.3546, 0.3741, 0.3937, 0.4132, 0.4328, 0.4523, 0.4719, 0.4914, 0.5110, 0.5306, 0.5501, 0.5697, 0.5893, 0.6088, 0.6284, 0.6480, 0.6675, 0.6871, 0.7067, 0.7263, 0.7458, 0.7654, 0.7850, 0.8045, 0.8241, 0.8436, 0.8632, 0.8827, 0.9023, 0.9218, 0.9414, 0.9609, 0.9805, -1.0000, -0.9805, -0.9609, -0.9414, -0.9218, -0.9023, -0.8827, -0.8632, -0.8436, -0.8240, -0.8045, -0.7849, -0.7653, -0.7458, -0.7262, -0.7066, -0.6871, -0.6675, -0.6479, -0.6283, -0.6088, -0.5892, -0.5696, -0.5501, -0.5305, -0.5109, -0.4914, -0.4718, -0.4523, -0.4327, -0.4132, -0.3936, -0.3741, -0.3545, -0.3350, -0.3155, -0.2959, -0.2764, -0.2569, -0.2374, -0.2179, -0.1984, -0.1789, -0.1594, -0.1400, -0.1205, -0.1010, -0.0816, -0.0622, -0.0427, -0.0233, -0.0039, 0.0155, 0.0349, 0.0543, 0.0737, 0.0930, 0.1124, 0.1317, 0.1511, 0.1704, 0.1897, 0.2090, 0.2283, 0.2476, 0.2668, 0.2861, 0.3053, 0.3245, 0.3437, 0.3629, 0.3821, 0.4012, 0.4204, 0.4395, 0.4586, 0.4777, 0.4968, 0.5159, 0.5349, 0.5540, 0.5730, 0.5920, 0.6109, 0.6299, 0.6489, 0.6678, 0.6867, 0.7056, 0.7244, 0.7433, 0.7621, 0.7809, 0.7997, 0.8185, 0.8372, 0.8559, 0.8747, 0.8933, 0.9120, 0.9306, 0.9492, 0.9678, -0.9636, -0.9440, -0.9246, -0.9051, -0.8856, -0.8662, -0.8467, -0.8273, -0.8079, -0.7885, -0.7692, -0.7498, -0.7305, -0.7111, -0.6918, -0.6726, -0.6533, -0.6341, -0.6148, -0.5956, -0.5764, -0.5573, -0.5381, -0.5190, -0.4999, -0.4808, -0.4617, -0.4427, -0.4237, -0.4047, -0.3857, -0.3667, -0.3478, -0.3289, -0.3100, -0.2911, -0.2723, -0.2535, -0.2347, -0.2159, -0.1972, -0.1784, -0.1597, -0.1411, -0.1224, -0.1038, -0.0852, -0.0666, -0.0481, -0.0296, -0.0111, 0.0074, 0.0258, 0.0442, 0.0626, 0.0810, 0.0993, 0.1176, 0.1358, 0.1541, 0.1723, 0.1905, 0.2086, 0.2267, 0.2448, 0.2629, 0.2809, 0.2989, 0.3168, 0.3348, 0.3527, 0.3705, 0.3884, 0.4062, 0.4239, 0.4417, 0.4594, 0.4771, 0.4947, 0.5123, 0.5299, 0.5474, 0.5649, 0.5824, 0.5998, 0.6172, 0.6346, 0.6519, 0.6692, 0.6864, 0.7036, 0.7208, 0.7380, 0.7551, 0.7721, 0.7892, 0.8062, 0.8231, 0.8400, 0.8569, 0.8738, 0.8906, -0.9003, -0.8817, -0.8632, -0.8447, -0.8263, -0.8079, -0.7895, -0.7712, -0.7529, -0.7346, -0.7163, -0.6981, -0.6800, -0.6618, -0.6437, -0.6256, -0.6076, -0.5896, -0.5716, -0.5537, -0.5358, -0.5179, -0.5001, -0.4823, -0.4646, -0.4469, -0.4292, -0.4116, -0.3940, -0.3764, -0.3589, -0.3414, -0.3239, -0.3065, -0.2892, -0.2718, -0.2545, -0.2373, -0.2201, -0.2029, -0.1858, -0.1687, -0.1516, -0.1346, -0.1176, -0.1007, -0.0838, -0.0670, -0.0502, -0.0334, -0.0167, -0.0000, 0.0166, 0.0332, 0.0498, 0.0663, 0.0828, 0.0992, 0.1156, 0.1319, 0.1482, 0.1644, 0.1806, 0.1968, 0.2129, 0.2290, 0.2450, 0.2610, 0.2769, 0.2928, 0.3086, 0.3244, 0.3402, 0.3559, 0.3715, 0.3871, 0.4027, 0.4182, 0.4337, 0.4491, 0.4644, 0.4798, 0.4950, 0.5103, 0.5255, 0.5406, 0.5557, 0.5707, 0.5857, 0.6006, 0.6155, 0.6303, 0.6451, 0.6599, 0.6746, 0.6892, 0.7038, 0.7183, 0.7328, 0.7472, 0.7616, 0.7760, 0.7902, -0.7797, -0.7630, -0.7464, -0.7298, -0.7133, -0.6968, -0.6804, -0.6640, -0.6476, -0.6313, -0.6151, -0.5989, -0.5827, -0.5666, -0.5505, -0.5345, -0.5186, -0.5026, -0.4868, -0.4710, -0.4552, -0.4395, -0.4238, -0.4082, -0.3926, -0.3771, -0.3616, -0.3462, -0.3308, -0.3155, -0.3002, -0.2850, -0.2698, -0.2547, -0.2397, -0.2247, -0.2097, -0.1948, -0.1799, -0.1651, -0.1504, -0.1356, -0.1210, -0.1064, -0.0918, -0.0774, -0.0629, -0.0485, -0.0342, -0.0199, -0.0057, 0.0085, 0.0226, 0.0367, 0.0507, 0.0647, 0.0786, 0.0924, 0.1062, 0.1200, 0.1337, 0.1473, 0.1609, 0.1744, 0.1879, 0.2013, 0.2146, 0.2279, 0.2412, 0.2544, 0.2675, 0.2806, 0.2936, 0.3066, 0.3195, 0.3324, 0.3452, 0.3579, 0.3706, 0.3833, 0.3958, 0.4083, 0.4208, 0.4332, 0.4456, 0.4579, 0.4701, 0.4823, 0.4944, 0.5065, 0.5185, 0.5304, 0.5423, 0.5541, 0.5659, 0.5776, 0.5893, 0.6009, 0.6124, 0.6239, 0.6353, 0.6467, -0.6478, -0.6336, -0.6195, -0.6054, -0.5914, -0.5775, -0.5636, -0.5498, -0.5360, -0.5223, -0.5086, -0.4950, -0.4814, -0.4679, -0.4545, -0.4411, -0.4278, -0.4145, -0.4013, -0.3881, -0.3750, -0.3620, -0.3490, -0.3361, -0.3232, -0.3104, -0.2976, -0.2849, -0.2723, -0.2597, -0.2472, -0.2347, -0.2223, -0.2100, -0.1977, -0.1855, -0.1733, -0.1612, -0.1491, -0.1371, -0.1252, -0.1133, -0.1015, -0.0897, -0.0780, -0.0664, -0.0548, -0.0433, -0.0318, -0.0204, -0.0090, 0.0023, 0.0135, 0.0247, 0.0358, 0.0468, 0.0578, 0.0687, 0.0796, 0.0904, 0.1012, 0.1119, 0.1225, 0.1331, 0.1436, 0.1541, 0.1645, 0.1748, 0.1851, 0.1953, 0.2055, 0.2156, 0.2256, 0.2356, 0.2455, 0.2553, 0.2651, 0.2749, 0.2846, 0.2942, 0.3037, 0.3132, 0.3227, 0.3321, 0.3414, 0.3506, 0.3598, 0.3690, 0.3781, 0.3871, 0.3960, 0.4049, 0.4138, 0.4225, 0.4313, 0.4399, 0.4485, 0.4571, 0.4655, 0.4740, 0.4823, 0.4906, -0.4988, -0.4876, -0.4764, -0.4653, -0.4542, -0.4432, -0.4323, -0.4214, -0.4105, -0.3998, -0.3891, -0.3784, -0.3678, -0.3573, -0.3468, -0.3364, -0.3261, -0.3158, -0.3056, -0.2954, -0.2853, -0.2752, -0.2653, -0.2553, -0.2455, -0.2357, -0.2259, -0.2162, -0.2066, -0.1970, -0.1875, -0.1781, -0.1687, -0.1594, -0.1501, -0.1409, -0.1317, -0.1226, -0.1136, -0.1046, -0.0957, -0.0869, -0.0781, -0.0694, -0.0607, -0.0521, -0.0435, -0.0350, -0.0266, -0.0182, -0.0099, -0.0016, 0.0066, 0.0147, 0.0228, 0.0308, 0.0388, 0.0467, 0.0545, 0.0623, 0.0700, 0.0777, 0.0853, 0.0928, 0.1003, 0.1078, 0.1151, 0.1224, 0.1297, 0.1369, 0.1440, 0.1511, 0.1581, 0.1651, 0.1720, 0.1789, 0.1857, 0.1924, 0.1991, 0.2057, 0.2123, 0.2188, 0.2252, 0.2316, 0.2379, 0.2442, 0.2504, 0.2566, 0.2627, 0.2687, 0.2747, 0.2807, 0.2865, 0.2924, 0.2981, 0.3038, 0.3095, 0.3151, 0.3206, 0.3261, 0.3315, 0.3369, 0.3422, -0.3394, -0.3313, -0.3232, -0.3152, -0.3073, -0.2994, -0.2916, -0.2838, -0.2761, -0.2684, -0.2608, -0.2533, -0.2458, -0.2384, -0.2310, -0.2237, -0.2165, -0.2093, -0.2021, -0.1951, -0.1880, -0.1811, -0.1741, -0.1673, -0.1605, -0.1538, -0.1471, -0.1404, -0.1339, -0.1273, -0.1209, -0.1145, -0.1081, -0.1018, -0.0956, -0.0894, -0.0833, -0.0772, -0.0712, -0.0652, -0.0593, -0.0535, -0.0477, -0.0419, -0.0362, -0.0306, -0.0250, -0.0195, -0.0140, -0.0086, -0.0032, 0.0021, 0.0074, 0.0126, 0.0177, 0.0228, 0.0279, 0.0329, 0.0378, 0.0427, 0.0476, 0.0524, 0.0571, 0.0618, 0.0664, 0.0710, 0.0755, 0.0800, 0.0844, 0.0888, 0.0931, 0.0974, 0.1016, 0.1058, 0.1099, 0.1140, 0.1180, 0.1220, 0.1259, 0.1298, 0.1336, 0.1374, 0.1411, 0.1448, 0.1484, 0.1520, 0.1555, 0.1590, 0.1625, 0.1659, 0.1692, 0.1725, 0.1757, 0.1789, 0.1821, 0.1852, 0.1882, 0.1912, 0.1942, 0.1971, 0.2000, 0.2028, -0.2040, -0.1988, -0.1936, -0.1885, -0.1835, -0.1785, -0.1735, -0.1686, -0.1638, -0.1590, -0.1542, -0.1495, -0.1448, -0.1402, -0.1357, -0.1312, -0.1267, -0.1223, -0.1179, -0.1136, -0.1093, -0.1051, -0.1010, -0.0968, -0.0928, -0.0887, -0.0848, -0.0808, -0.0769, -0.0731, -0.0693, -0.0655, -0.0618, -0.0582, -0.0546, -0.0510, -0.0475, -0.0440, -0.0406, -0.0372, -0.0339, -0.0306, -0.0273, -0.0241, -0.0209, -0.0178, -0.0147, -0.0117, -0.0087, -0.0058, -0.0029, -0.0000, 0.0028, 0.0056, 0.0083, 0.0110, 0.0137, 0.0163, 0.0189, 0.0214, 0.0239, 0.0263, 0.0287, 0.0311, 0.0334, 0.0357, 0.0380, 0.0402, 0.0424, 0.0445, 0.0466, 0.0486, 0.0507, 0.0526, 0.0546, 0.0565, 0.0584, 0.0602, 0.0620, 0.0637, 0.0655, 0.0671, 0.0688, 0.0704, 0.0720, 0.0735, 0.0750, 0.0765, 0.0779, 0.0793, 0.0807, 0.0820, 0.0833, 0.0846, 0.0858, 0.0870, 0.0882, 0.0893, 0.0904, 0.0915, 0.0925, 0.0935, 0.0945, -0.0925, -0.0898, -0.0871, -0.0845, -0.0819, -0.0794, -0.0769, -0.0744, -0.0720, -0.0696, -0.0672, -0.0649, -0.0626, -0.0604, -0.0582, -0.0560, -0.0538, -0.0517, -0.0497, -0.0476, -0.0456, -0.0436, -0.0417, -0.0398, -0.0379, -0.0361, -0.0343, -0.0325, -0.0308, -0.0291, -0.0274, -0.0258, -0.0242, -0.0226, -0.0211, -0.0196, -0.0181, -0.0166, -0.0152, -0.0138, -0.0124, -0.0111, -0.0098, -0.0085, -0.0073, -0.0061, -0.0049, -0.0037, -0.0026, -0.0015, -0.0004, 0.0006, 0.0016, 0.0026, 0.0036, 0.0046, 0.0055, 0.0064, 0.0072, 0.0081, 0.0089, 0.0097, 0.0104, 0.0112, 0.0119, 0.0126, 0.0133, 0.0139, 0.0145, 0.0151, 0.0157, 0.0163, 0.0168, 0.0173, 0.0178, 0.0183, 0.0188, 0.0192, 0.0196, 0.0200, 0.0204, 0.0207, 0.0210, 0.0214, 0.0216, 0.0219, 0.0222, 0.0224, 0.0226, 0.0228, 0.0230, 0.0232, 0.0234, 0.0235, 0.0236, 0.0237, 0.0238, 0.0239, 0.0239, 0.0240, 0.0240, 0.0240, -0.0236, -0.0227, -0.0218, -0.0210, -0.0201, -0.0193, -0.0185, -0.0177, -0.0169, -0.0162, -0.0154, -0.0147, -0.0141, -0.0134, -0.0127, -0.0121, -0.0115, -0.0109, -0.0103, -0.0098, -0.0092, -0.0087, -0.0082, -0.0077, -0.0073, -0.0068, -0.0064, -0.0060, -0.0056, -0.0052, -0.0048, -0.0044, -0.0041, -0.0038, -0.0035, -0.0032, -0.0029, -0.0026, -0.0023, -0.0021, -0.0018, -0.0016, -0.0014, -0.0012, -0.0010, -0.0008, -0.0007, -0.0005, -0.0004, -0.0002, -0.0001, 0.0000, 0.0001, 0.0002, 0.0003, 0.0004, 0.0005, 0.0006, 0.0006, 0.0007, 0.0007, 0.0007, 0.0008, 0.0008, 0.0008, 0.0008, 0.0009, 0.0009, 0.0009, 0.0009, 0.0008, 0.0008, 0.0008, 0.0008, 0.0008, 0.0008, 0.0007, 0.0007, 0.0007, 0.0006, 0.0006, 0.0006, 0.0005, 0.0005, 0.0004, 0.0004, 0.0004, 0.0003, 0.0003, 0.0003, 0.0002, 0.0002, 0.0002, 0.0001, 0.0001, 0.0001, 0.0001, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000};