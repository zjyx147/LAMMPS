const char * pair_gpu_build_kernel = 
"	.version 1.4\n"
"	.target sm_13\n"
"	.tex .u64 neigh_tex;\n"
"	.entry transpose (\n"
"		.param .u64 __cudaparm_transpose_out,\n"
"		.param .u64 __cudaparm_transpose_in,\n"
"		.param .s32 __cudaparm_transpose_columns_in,\n"
"		.param .s32 __cudaparm_transpose_rows_in)\n"
"	{\n"
"	.reg .u16 %rh<4>;\n"
"	.reg .u32 %r<30>;\n"
"	.reg .u64 %rd<23>;\n"
"	.reg .f32 %f<4>;\n"
"	.reg .pred %p<4>;\n"
"	.shared .align 4 .b8 __cuda_block24[288];\n"
"	.loc	14	62	0\n"
"$LBB1_transpose:\n"
"	mov.u16 	%rh1, %ctaid.x;\n"
"	mul.wide.u16 	%r1, %rh1, 8;\n"
"	mov.u16 	%rh2, %ctaid.y;\n"
"	mul.wide.u16 	%r2, %rh2, 8;\n"
"	cvt.u32.u16 	%r3, %tid.x;\n"
"	add.u32 	%r4, %r1, %r3;\n"
"	cvt.u32.u16 	%r5, %tid.y;\n"
"	add.u32 	%r6, %r2, %r5;\n"
"	ld.param.u32 	%r7, [__cudaparm_transpose_rows_in];\n"
"	ld.param.u32 	%r8, [__cudaparm_transpose_columns_in];\n"
"	set.lt.u32.u32 	%r9, %r4, %r8;\n"
"	neg.s32 	%r10, %r9;\n"
"	set.lt.u32.u32 	%r11, %r6, %r7;\n"
"	neg.s32 	%r12, %r11;\n"
"	and.b32 	%r13, %r10, %r12;\n"
"	mov.u32 	%r14, 0;\n"
"	setp.eq.s32 	%p1, %r13, %r14;\n"
"	@%p1 bra 	$Lt_0_2306;\n"
"	.loc	14	74	0\n"
"	mov.u64 	%rd1, __cuda_block24;\n"
"	ld.param.u64 	%rd2, [__cudaparm_transpose_in];\n"
"	mul.lo.u32 	%r15, %r6, %r8;\n"
"	add.u32 	%r16, %r4, %r15;\n"
"	cvt.u64.u32 	%rd3, %r16;\n"
"	mul.lo.u64 	%rd4, %rd3, 4;\n"
"	add.u64 	%rd5, %rd2, %rd4;\n"
"	ld.global.s32 	%r17, [%rd5+0];\n"
"	cvt.rn.f32.s32 	%f1, %r17;\n"
"	cvt.u64.u32 	%rd6, %r3;\n"
"	cvt.u64.u32 	%rd7, %r5;\n"
"	mul.lo.u64 	%rd8, %rd7, 9;\n"
"	add.u64 	%rd9, %rd6, %rd8;\n"
"	mul.lo.u64 	%rd10, %rd9, 4;\n"
"	add.u64 	%rd11, %rd1, %rd10;\n"
"	st.shared.f32 	[%rd11+0], %f1;\n"
"$Lt_0_2306:\n"
"	mov.u64 	%rd1, __cuda_block24;\n"
"	.loc	14	76	0\n"
"	bar.sync 	0;\n"
"	add.u32 	%r18, %r1, %r5;\n"
"	add.u32 	%r19, %r2, %r3;\n"
"	set.lt.u32.u32 	%r20, %r18, %r8;\n"
"	neg.s32 	%r21, %r20;\n"
"	set.lt.u32.u32 	%r22, %r19, %r7;\n"
"	neg.s32 	%r23, %r22;\n"
"	and.b32 	%r24, %r21, %r23;\n"
"	mov.u32 	%r25, 0;\n"
"	setp.eq.s32 	%p2, %r24, %r25;\n"
"	@%p2 bra 	$Lt_0_2818;\n"
"	.loc	14	81	0\n"
"	cvt.u64.u32 	%rd12, %r5;\n"
"	cvt.u64.u32 	%rd13, %r3;\n"
"	mul.lo.u64 	%rd14, %rd13, 9;\n"
"	add.u64 	%rd15, %rd12, %rd14;\n"
"	mul.lo.u64 	%rd16, %rd15, 4;\n"
"	add.u64 	%rd17, %rd1, %rd16;\n"
"	ld.shared.f32 	%f2, [%rd17+0];\n"
"	cvt.rzi.s32.f32 	%r26, %f2;\n"
"	ld.param.u64 	%rd18, [__cudaparm_transpose_out];\n"
"	mul.lo.u32 	%r27, %r18, %r7;\n"
"	add.u32 	%r28, %r19, %r27;\n"
"	cvt.u64.u32 	%rd19, %r28;\n"
"	mul.lo.u64 	%rd20, %rd19, 4;\n"
"	add.u64 	%rd21, %rd18, %rd20;\n"
"	st.global.s32 	[%rd21+0], %r26;\n"
"$Lt_0_2818:\n"
"	.loc	14	82	0\n"
"	exit;\n"
"$LDWend_transpose:\n"
"	}\n"
"	.entry calc_cell_id (\n"
"		.param .u64 __cudaparm_calc_cell_id_pos,\n"
"		.param .u64 __cudaparm_calc_cell_id_cell_id,\n"
"		.param .u64 __cudaparm_calc_cell_id_particle_id,\n"
"		.param .f32 __cudaparm_calc_cell_id_boxlo0,\n"
"		.param .f32 __cudaparm_calc_cell_id_boxlo1,\n"
"		.param .f32 __cudaparm_calc_cell_id_boxlo2,\n"
"		.param .f32 __cudaparm_calc_cell_id_boxhi0,\n"
"		.param .f32 __cudaparm_calc_cell_id_boxhi1,\n"
"		.param .f32 __cudaparm_calc_cell_id_boxhi2,\n"
"		.param .f32 __cudaparm_calc_cell_id_cell_size,\n"
"		.param .s32 __cudaparm_calc_cell_id_ncellx,\n"
"		.param .s32 __cudaparm_calc_cell_id_ncelly,\n"
"		.param .s32 __cudaparm_calc_cell_id_nall)\n"
"	{\n"
"	.reg .u16 %rh<4>;\n"
"	.reg .u32 %r<20>;\n"
"	.reg .u64 %rd<8>;\n"
"	.reg .f32 %f<35>;\n"
"	.reg .f64 %fd<11>;\n"
"	.reg .pred %p<3>;\n"
"	.loc	14	88	0\n"
"$LBB1_calc_cell_id:\n"
"	cvt.u32.u16 	%r1, %tid.x;\n"
"	mov.u16 	%rh1, %ctaid.x;\n"
"	mov.u16 	%rh2, %ntid.x;\n"
"	mul.wide.u16 	%r2, %rh1, %rh2;\n"
"	add.u32 	%r3, %r1, %r2;\n"
"	ld.param.s32 	%r4, [__cudaparm_calc_cell_id_nall];\n"
"	setp.le.s32 	%p1, %r4, %r3;\n"
"	@%p1 bra 	$Lt_1_1026;\n"
"	mov.s32 	%r5, %r3;\n"
"	mov.s32 	%r6, 0;\n"
"	mov.s32 	%r7, 0;\n"
"	mov.s32 	%r8, 0;\n"
"	tex.1d.v4.f32.s32 {%f1,%f2,%f3,%f4},[neigh_tex,{%r5,%r6,%r7,%r8}];\n"
"	.loc	14	92	0\n"
"	mov.f32 	%f5, %f1;\n"
"	mov.f32 	%f6, %f2;\n"
"	mov.f32 	%f7, %f3;\n"
"	.loc	14	105	0\n"
"	ld.param.f32 	%f8, [__cudaparm_calc_cell_id_cell_size];\n"
"	neg.f32 	%f9, %f8;\n"
"	ld.param.f32 	%f10, [__cudaparm_calc_cell_id_boxlo0];\n"
"	ld.param.f32 	%f11, [__cudaparm_calc_cell_id_boxlo2];\n"
"	ld.param.f32 	%f12, [__cudaparm_calc_cell_id_boxlo1];\n"
"	ld.param.u32 	%r9, [__cudaparm_calc_cell_id_ncellx];\n"
"	ld.param.u32 	%r10, [__cudaparm_calc_cell_id_ncelly];\n"
"	ld.param.f32 	%f13, [__cudaparm_calc_cell_id_boxhi2];\n"
"	sub.f32 	%f14, %f13, %f11;\n"
"	add.f32 	%f15, %f8, %f14;\n"
"	sub.f32 	%f16, %f7, %f11;\n"
"	max.f32 	%f17, %f9, %f16;\n"
"	min.f32 	%f18, %f15, %f17;\n"
"	div.approx.f32 	%f19, %f18, %f8;\n"
"	cvt.f64.f32 	%fd1, %f19;\n"
"	mov.f64 	%fd2, 0d3ff0000000000000;	\n"
"	add.f64 	%fd3, %fd1, %fd2;\n"
"	cvt.rzi.u32.f64 	%r11, %fd3;\n"
"	mul.lo.u32 	%r12, %r9, %r11;\n"
"	mul.lo.u32 	%r13, %r10, %r12;\n"
"	ld.param.f32 	%f20, [__cudaparm_calc_cell_id_boxhi1];\n"
"	sub.f32 	%f21, %f20, %f12;\n"
"	add.f32 	%f22, %f8, %f21;\n"
"	sub.f32 	%f23, %f6, %f12;\n"
"	max.f32 	%f24, %f9, %f23;\n"
"	min.f32 	%f25, %f22, %f24;\n"
"	div.approx.f32 	%f26, %f25, %f8;\n"
"	cvt.f64.f32 	%fd4, %f26;\n"
"	mov.f64 	%fd5, 0d3ff0000000000000;	\n"
"	add.f64 	%fd6, %fd4, %fd5;\n"
"	cvt.rzi.u32.f64 	%r14, %fd6;\n"
"	mul.lo.u32 	%r15, %r9, %r14;\n"
"	add.u32 	%r16, %r13, %r15;\n"
"	ld.param.f32 	%f27, [__cudaparm_calc_cell_id_boxhi0];\n"
"	sub.f32 	%f28, %f27, %f10;\n"
"	add.f32 	%f29, %f8, %f28;\n"
"	sub.f32 	%f30, %f5, %f10;\n"
"	max.f32 	%f31, %f9, %f30;\n"
"	min.f32 	%f32, %f29, %f31;\n"
"	div.approx.f32 	%f33, %f32, %f8;\n"
"	cvt.f64.f32 	%fd7, %f33;\n"
"	mov.f64 	%fd8, 0d3ff0000000000000;	\n"
"	add.f64 	%fd9, %fd7, %fd8;\n"
"	cvt.rzi.u32.f64 	%r17, %fd9;\n"
"	add.u32 	%r18, %r16, %r17;\n"
"	.loc	14	109	0\n"
"	cvt.u64.s32 	%rd1, %r3;\n"
"	mul.lo.u64 	%rd2, %rd1, 4;\n"
"	ld.param.u64 	%rd3, [__cudaparm_calc_cell_id_cell_id];\n"
"	add.u64 	%rd4, %rd3, %rd2;\n"
"	st.global.u32 	[%rd4+0], %r18;\n"
"	.loc	14	110	0\n"
"	ld.param.u64 	%rd5, [__cudaparm_calc_cell_id_particle_id];\n"
"	add.u64 	%rd6, %rd5, %rd2;\n"
"	st.global.s32 	[%rd6+0], %r3;\n"
"$Lt_1_1026:\n"
"	.loc	14	112	0\n"
"	exit;\n"
"$LDWend_calc_cell_id:\n"
"	}\n"
"	.entry kernel_calc_cell_counts (\n"
"		.param .u64 __cudaparm_kernel_calc_cell_counts_cell_id,\n"
"		.param .u64 __cudaparm_kernel_calc_cell_counts_cell_counts,\n"
"		.param .s32 __cudaparm_kernel_calc_cell_counts_nall,\n"
"		.param .s32 __cudaparm_kernel_calc_cell_counts_ncell)\n"
"	{\n"
"	.reg .u16 %rh<4>;\n"
"	.reg .u32 %r<31>;\n"
"	.reg .u64 %rd<15>;\n"
"	.reg .pred %p<13>;\n"
"	.loc	14	115	0\n"
"$LBB1_kernel_calc_cell_counts:\n"
"	mov.u16 	%rh1, %ctaid.x;\n"
"	mov.u16 	%rh2, %ntid.x;\n"
"	mul.wide.u16 	%r1, %rh1, %rh2;\n"
"	cvt.u32.u16 	%r2, %tid.x;\n"
"	add.u32 	%r3, %r2, %r1;\n"
"	ld.param.s32 	%r4, [__cudaparm_kernel_calc_cell_counts_nall];\n"
"	setp.gt.s32 	%p1, %r4, %r3;\n"
"	@!%p1 bra 	$Lt_2_7426;\n"
"	.loc	14	118	0\n"
"	ld.param.u64 	%rd1, [__cudaparm_kernel_calc_cell_counts_cell_id];\n"
"	cvt.u64.s32 	%rd2, %r3;\n"
"	mul.lo.u64 	%rd3, %rd2, 4;\n"
"	add.u64 	%rd4, %rd1, %rd3;\n"
"	ld.global.s32 	%r5, [%rd4+0];\n"
"	mov.u32 	%r6, 0;\n"
"	setp.ne.s32 	%p2, %r3, %r6;\n"
"	@%p2 bra 	$Lt_2_7938;\n"
"	add.s32 	%r7, %r5, 1;\n"
"	mov.u32 	%r8, 0;\n"
"	setp.le.s32 	%p3, %r7, %r8;\n"
"	@%p3 bra 	$Lt_2_8450;\n"
"	mov.s32 	%r9, %r7;\n"
"	ld.param.u64 	%rd5, [__cudaparm_kernel_calc_cell_counts_cell_counts];\n"
"	mov.s32 	%r10, 0;\n"
"	mov.s32 	%r11, %r9;\n"
"$Lt_2_8962:\n"
"	.loc	14	123	0\n"
"	mov.s32 	%r12, 0;\n"
"	st.global.s32 	[%rd5+0], %r12;\n"
"	add.s32 	%r10, %r10, 1;\n"
"	add.u64 	%rd5, %rd5, 4;\n"
"	setp.ne.s32 	%p4, %r7, %r10;\n"
"	@%p4 bra 	$Lt_2_8962;\n"
"$Lt_2_8450:\n"
"$Lt_2_7938:\n"
"	sub.s32 	%r13, %r4, 1;\n"
"	setp.ne.s32 	%p5, %r3, %r13;\n"
"	@%p5 bra 	$Lt_2_9474;\n"
"	.loc	14	126	0\n"
"	add.s32 	%r7, %r5, 1;\n"
"	mov.s32 	%r14, %r7;\n"
"	ld.param.s32 	%r15, [__cudaparm_kernel_calc_cell_counts_ncell];\n"
"	setp.gt.s32 	%p6, %r7, %r15;\n"
"	@%p6 bra 	$Lt_2_9986;\n"
"	sub.s32 	%r16, %r15, %r5;\n"
"	add.s32 	%r17, %r15, 1;\n"
"	ld.param.u64 	%rd6, [__cudaparm_kernel_calc_cell_counts_cell_counts];\n"
"	cvt.u64.s32 	%rd7, %r7;\n"
"	mul.lo.u64 	%rd8, %rd7, 4;\n"
"	add.u64 	%rd9, %rd6, %rd8;\n"
"	mov.s32 	%r18, %r16;\n"
"$Lt_2_10498:\n"
"	.loc	14	127	0\n"
"	st.global.s32 	[%rd9+0], %r4;\n"
"	add.s32 	%r14, %r14, 1;\n"
"	add.u64 	%rd9, %rd9, 4;\n"
"	setp.ne.s32 	%p7, %r17, %r14;\n"
"	@%p7 bra 	$Lt_2_10498;\n"
"$Lt_2_9986:\n"
"$Lt_2_9474:\n"
"	selp.s32 	%r19, 1, 0, %p1;\n"
"	mov.s32 	%r20, 0;\n"
"	set.gt.u32.s32 	%r21, %r3, %r20;\n"
"	neg.s32 	%r22, %r21;\n"
"	and.b32 	%r23, %r19, %r22;\n"
"	mov.u32 	%r24, 0;\n"
"	setp.eq.s32 	%p8, %r23, %r24;\n"
"	@%p8 bra 	$Lt_2_11010;\n"
"	.loc	14	131	0\n"
"	ld.global.s32 	%r25, [%rd4+-4];\n"
"	setp.eq.s32 	%p9, %r5, %r25;\n"
"	@%p9 bra 	$Lt_2_11522;\n"
"	.loc	14	133	0\n"
"	add.s32 	%r26, %r25, 1;\n"
"	mov.s32 	%r27, %r26;\n"
"	setp.gt.s32 	%p10, %r26, %r5;\n"
"	@%p10 bra 	$Lt_2_12034;\n"
"	sub.s32 	%r28, %r5, %r25;\n"
"	add.s32 	%r7, %r5, 1;\n"
"	ld.param.u64 	%rd10, [__cudaparm_kernel_calc_cell_counts_cell_counts];\n"
"	cvt.u64.s32 	%rd11, %r26;\n"
"	mul.lo.u64 	%rd12, %rd11, 4;\n"
"	add.u64 	%rd13, %rd10, %rd12;\n"
"	mov.s32 	%r29, %r28;\n"
"$Lt_2_12546:\n"
"	.loc	14	134	0\n"
"	st.global.s32 	[%rd13+0], %r3;\n"
"	add.s32 	%r27, %r27, 1;\n"
"	add.u64 	%rd13, %rd13, 4;\n"
"	setp.ne.s32 	%p11, %r7, %r27;\n"
"	@%p11 bra 	$Lt_2_12546;\n"
"$Lt_2_12034:\n"
"$Lt_2_11522:\n"
"$Lt_2_11010:\n"
"$Lt_2_7426:\n"
"	.loc	14	138	0\n"
"	exit;\n"
"$LDWend_kernel_calc_cell_counts:\n"
"	}\n"
"	.entry calc_neigh_list_cell (\n"
"		.param .u64 __cudaparm_calc_neigh_list_cell_pos,\n"
"		.param .u64 __cudaparm_calc_neigh_list_cell_cell_particle_id,\n"
"		.param .u64 __cudaparm_calc_neigh_list_cell_cell_counts,\n"
"		.param .u64 __cudaparm_calc_neigh_list_cell_nbor_list,\n"
"		.param .u64 __cudaparm_calc_neigh_list_cell_host_nbor_list,\n"
"		.param .s32 __cudaparm_calc_neigh_list_cell_neigh_bin_size,\n"
"		.param .f32 __cudaparm_calc_neigh_list_cell_cell_size,\n"
"		.param .s32 __cudaparm_calc_neigh_list_cell_ncellx,\n"
"		.param .s32 __cudaparm_calc_neigh_list_cell_ncelly,\n"
"		.param .s32 __cudaparm_calc_neigh_list_cell_ncellz,\n"
"		.param .s32 __cudaparm_calc_neigh_list_cell_inum,\n"
"		.param .s32 __cudaparm_calc_neigh_list_cell_nt,\n"
"		.param .s32 __cudaparm_calc_neigh_list_cell_nall)\n"
"	{\n"
"	.reg .u32 %r<105>;\n"
"	.reg .u64 %rd<43>;\n"
"	.reg .f32 %f<43>;\n"
"	.reg .f64 %fd<4>;\n"
"	.reg .pred %p<24>;\n"
"	.shared .align 16 .b8 __cuda_pos_sh480[1024];\n"
"	.shared .align 4 .b8 __cuda_cell_list_sh1504[256];\n"
"	.loc	14	148	0\n"
"$LBB1_calc_neigh_list_cell:\n"
"	.loc	14	160	0\n"
"	ld.param.u32 	%r1, [__cudaparm_calc_neigh_list_cell_ncelly];\n"
"	cvt.u32.u16 	%r2, %ctaid.y;\n"
"	rem.u32 	%r3, %r2, %r1;\n"
"	div.u32 	%r4, %r2, %r1;\n"
"	ld.param.s32 	%r5, [__cudaparm_calc_neigh_list_cell_ncellx];\n"
"	mul.lo.s32 	%r6, %r5, %r3;\n"
"	mul.lo.s32 	%r7, %r5, %r4;\n"
"	mul.lo.s32 	%r8, %r7, %r1;\n"
"	cvt.s32.u16 	%r9, %ctaid.x;\n"
"	ld.param.u64 	%rd1, [__cudaparm_calc_neigh_list_cell_cell_counts];\n"
"	add.s32 	%r10, %r6, %r8;\n"
"	add.s32 	%r11, %r9, %r10;\n"
"	cvt.u64.s32 	%rd2, %r11;\n"
"	mul.lo.u64 	%rd3, %rd2, 4;\n"
"	add.u64 	%rd4, %rd1, %rd3;\n"
"	ld.global.s32 	%r12, [%rd4+0];\n"
"	.loc	14	161	0\n"
"	ld.global.s32 	%r13, [%rd4+4];\n"
"	.loc	14	169	0\n"
"	sub.s32 	%r14, %r13, %r12;\n"
"	cvt.u32.u16 	%r15, %ntid.x;\n"
"	cvt.rn.f32.u32 	%f1, %r15;\n"
"	cvt.rn.f32.s32 	%f2, %r14;\n"
"	div.approx.f32 	%f3, %f2, %f1;\n"
"	cvt.rpi.f32.f32 	%f4, %f3;\n"
"	mov.f32 	%f5, 0f00000000;     	\n"
"	setp.gt.f32 	%p1, %f4, %f5;\n"
"	@!%p1 bra 	$Lt_3_14594;\n"
"	sub.s32 	%r16, %r3, 1;\n"
"	mov.s32 	%r17, 0;\n"
"	max.s32 	%r18, %r16, %r17;\n"
"	sub.s32 	%r19, %r1, 1;\n"
"	add.s32 	%r20, %r3, 1;\n"
"	min.s32 	%r21, %r19, %r20;\n"
"	ld.param.s32 	%r22, [__cudaparm_calc_neigh_list_cell_ncellz];\n"
"	sub.s32 	%r23, %r22, 1;\n"
"	add.s32 	%r24, %r4, 1;\n"
"	min.s32 	%r25, %r23, %r24;\n"
"	sub.s32 	%r26, %r9, 1;\n"
"	mov.s32 	%r27, 0;\n"
"	max.s32 	%r28, %r26, %r27;\n"
"	add.s32 	%r29, %r9, 1;\n"
"	sub.s32 	%r30, %r5, 1;\n"
"	min.s32 	%r31, %r29, %r30;\n"
"	cvt.s32.u16 	%r32, %tid.x;\n"
"	add.s32 	%r33, %r12, %r32;\n"
"	mov.u32 	%r34, 0;\n"
"	ld.param.s32 	%r35, [__cudaparm_calc_neigh_list_cell_inum];\n"
"	cvt.u64.s32 	%rd5, %r35;\n"
"	sub.s32 	%r36, %r4, 1;\n"
"	mov.s32 	%r37, %r33;\n"
"	mov.s32 	%r38, 0;\n"
"	max.s32 	%r39, %r36, %r38;\n"
"	setp.ge.s32 	%p2, %r25, %r39;\n"
"	ld.param.s32 	%r40, [__cudaparm_calc_neigh_list_cell_nt];\n"
"	ld.param.s32 	%r41, [__cudaparm_calc_neigh_list_cell_nall];\n"
"	mov.s32 	%r42, 0;\n"
"	mov.u64 	%rd6, __cuda_pos_sh480;\n"
"	mov.u64 	%rd7, __cuda_cell_list_sh1504;\n"
"$Lt_3_15106:\n"
"	.loc	14	171	0\n"
"	mov.s32 	%r43, %r41;\n"
"	setp.ge.s32 	%p3, %r37, %r13;\n"
"	@%p3 bra 	$Lt_3_15362;\n"
"	.loc	14	177	0\n"
"	ld.param.u64 	%rd8, [__cudaparm_calc_neigh_list_cell_cell_particle_id];\n"
"	add.u32 	%r44, %r33, %r34;\n"
"	cvt.u64.s32 	%rd9, %r44;\n"
"	mul.lo.u64 	%rd10, %rd9, 4;\n"
"	add.u64 	%rd11, %rd8, %rd10;\n"
"	ld.global.s32 	%r43, [%rd11+0];\n"
"$Lt_3_15362:\n"
"	setp.lt.s32 	%p4, %r43, %r40;\n"
"	@!%p4 bra 	$Lt_3_15874;\n"
"	mov.s32 	%r45, %r43;\n"
"	mov.s32 	%r46, 0;\n"
"	mov.s32 	%r47, 0;\n"
"	mov.s32 	%r48, 0;\n"
"	tex.1d.v4.f32.s32 {%f6,%f7,%f8,%f9},[neigh_tex,{%r45,%r46,%r47,%r48}];\n"
"	.loc	14	180	0\n"
"	mov.f32 	%f10, %f6;\n"
"	mov.f32 	%f11, %f7;\n"
"	mov.f32 	%f12, %f8;\n"
"	mov.f32 	%f13, %f10;\n"
"	mov.f32 	%f14, %f11;\n"
"	mov.f32 	%f15, %f12;\n"
"$Lt_3_15874:\n"
"	cvt.u64.s32 	%rd12, %r43;\n"
"	mul.lo.u64 	%rd13, %rd12, 4;\n"
"	setp.ge.s32 	%p5, %r43, %r35;\n"
"	@%p5 bra 	$Lt_3_16642;\n"
"	.loc	14	183	0\n"
"	mov.s32 	%r49, %r35;\n"
"	.loc	14	184	0\n"
"	ld.param.u64 	%rd14, [__cudaparm_calc_neigh_list_cell_nbor_list];\n"
"	add.u64 	%rd15, %rd12, %rd5;\n"
"	mul.lo.u64 	%rd16, %rd15, 4;\n"
"	add.u64 	%rd17, %rd14, %rd16;\n"
"	.loc	14	186	0\n"
"	add.u64 	%rd18, %rd13, %rd14;\n"
"	st.global.s32 	[%rd18+0], %r43;\n"
"	bra.uni 	$Lt_3_16386;\n"
"$Lt_3_16642:\n"
"	.loc	14	188	0\n"
"	sub.s32 	%r49, %r40, %r35;\n"
"	.loc	14	189	0\n"
"	ld.param.u64 	%rd19, [__cudaparm_calc_neigh_list_cell_host_nbor_list];\n"
"	add.u64 	%rd20, %rd19, %rd13;\n"
"	mul.lo.u64 	%rd21, %rd5, 4;\n"
"	sub.u64 	%rd17, %rd20, %rd21;\n"
"$Lt_3_16386:\n"
"	cvt.u64.s32 	%rd22, %r49;\n"
"	mul.lo.u64 	%rd23, %rd22, 4;\n"
"	add.u64 	%rd24, %rd17, %rd23;\n"
"	.loc	14	195	0\n"
"	mov.s32 	%r50, %r39;\n"
"	mov.s32 	%r51, 0;\n"
"	@!%p2 bra 	$Lt_3_25090;\n"
"	sub.s32 	%r52, %r25, %r39;\n"
"	add.s32 	%r53, %r52, 1;\n"
"	setp.le.s32 	%p6, %r18, %r21;\n"
"	add.s32 	%r54, %r25, 1;\n"
"	mov.s32 	%r55, %r53;\n"
"$Lt_3_17410:\n"
"	.loc	14	196	0\n"
"	mov.s32 	%r56, %r18;\n"
"	@!%p6 bra 	$Lt_3_17666;\n"
"	sub.s32 	%r57, %r21, %r18;\n"
"	add.s32 	%r58, %r57, 1;\n"
"	setp.ge.s32 	%p7, %r31, %r28;\n"
"	add.s32 	%r59, %r21, 1;\n"
"	mov.s32 	%r60, %r58;\n"
"$Lt_3_18178:\n"
"	@!%p7 bra 	$Lt_3_18434;\n"
"	sub.s32 	%r61, %r31, %r28;\n"
"	add.s32 	%r62, %r61, 1;\n"
"	mul.lo.s32 	%r63, %r56, %r5;\n"
"	mul.lo.s32 	%r64, %r50, %r5;\n"
"	mul.lo.s32 	%r65, %r64, %r1;\n"
"	add.s32 	%r66, %r31, 1;\n"
"	add.s32 	%r67, %r63, %r65;\n"
"	add.s32 	%r68, %r67, %r28;\n"
"	add.s32 	%r69, %r66, %r67;\n"
"	cvt.u64.s32 	%rd25, %r68;\n"
"	mul.lo.u64 	%rd26, %rd25, 4;\n"
"	add.u64 	%rd27, %rd1, %rd26;\n"
"	mov.s32 	%r70, %r62;\n"
"$Lt_3_18946:\n"
"	.loc	14	201	0\n"
"	ld.global.s32 	%r71, [%rd27+0];\n"
"	.loc	14	202	0\n"
"	ld.global.s32 	%r72, [%rd27+4];\n"
"	.loc	14	206	0\n"
"	sub.s32 	%r73, %r72, %r71;\n"
"	cvt.rn.f32.s32 	%f16, %r73;\n"
"	mov.f32 	%f17, 0f42800000;    	\n"
"	div.approx.f32 	%f18, %f16, %f17;\n"
"	cvt.rpi.f32.f32 	%f19, %f18;\n"
"	cvt.rzi.s32.f32 	%r74, %f19;\n"
"	mov.u32 	%r75, 0;\n"
"	setp.le.s32 	%p8, %r74, %r75;\n"
"	@%p8 bra 	$Lt_3_19202;\n"
"	mov.s32 	%r76, %r74;\n"
"	mov.s32 	%r77, 0;\n"
"	setp.lt.s32 	%p9, %r43, %r40;\n"
"	mul.lo.s32 	%r78, %r74, 64;\n"
"	mov.s32 	%r79, %r76;\n"
"$Lt_3_19714:\n"
"	.loc	14	209	0\n"
"	sub.s32 	%r80, %r73, %r77;\n"
"	mov.s32 	%r81, 64;\n"
"	min.s32 	%r82, %r80, %r81;\n"
"	setp.le.s32 	%p10, %r82, %r32;\n"
"	@%p10 bra 	$Lt_3_19970;\n"
"	.loc	14	212	0\n"
"	ld.param.u64 	%rd28, [__cudaparm_calc_neigh_list_cell_cell_particle_id];\n"
"	add.s32 	%r83, %r77, %r32;\n"
"	add.s32 	%r84, %r71, %r83;\n"
"	cvt.s64.s32 	%rd29, %r84;\n"
"	mul.lo.u64 	%rd30, %rd29, 4;\n"
"	add.u64 	%rd31, %rd28, %rd30;\n"
"	ld.global.s32 	%r85, [%rd31+0];\n"
"	.loc	14	213	0\n"
"	cvt.u64.s32 	%rd32, %r32;\n"
"	mul.lo.u64 	%rd33, %rd32, 4;\n"
"	add.u64 	%rd34, %rd7, %rd33;\n"
"	st.shared.s32 	[%rd34+0], %r85;\n"
"	mov.s32 	%r86, %r85;\n"
"	mov.s32 	%r87, 0;\n"
"	mov.s32 	%r88, 0;\n"
"	mov.s32 	%r89, 0;\n"
"	tex.1d.v4.f32.s32 {%f20,%f21,%f22,%f23},[neigh_tex,{%r86,%r87,%r88,%r89}];\n"
"	.loc	14	214	0\n"
"	mov.f32 	%f24, %f20;\n"
"	mov.f32 	%f25, %f21;\n"
"	mov.f32 	%f26, %f22;\n"
"	.loc	14	215	0\n"
"	mul.lo.u64 	%rd35, %rd32, 16;\n"
"	add.u64 	%rd36, %rd6, %rd35;\n"
"	st.shared.f32 	[%rd36+0], %f24;\n"
"	.loc	14	216	0\n"
"	st.shared.f32 	[%rd36+4], %f25;\n"
"	.loc	14	217	0\n"
"	st.shared.f32 	[%rd36+8], %f26;\n"
"$Lt_3_19970:\n"
"	.loc	14	219	0\n"
"	bar.sync 	0;\n"
"	@!%p9 bra 	$Lt_3_20994;\n"
"	mov.u32 	%r90, 0;\n"
"	setp.le.s32 	%p11, %r82, %r90;\n"
"	@%p11 bra 	$Lt_3_20994;\n"
"	mov.s32 	%r91, %r82;\n"
"	mov.u64 	%rd37, 0;\n"
"	setp.lt.s32 	%p12, %r43, %r35;\n"
"	selp.s32 	%r92, 1, 0, %p12;\n"
"	mov.s64 	%rd38, %rd7;\n"
"	mov.s32 	%r93, 0;\n"
"	mov.s32 	%r94, %r91;\n"
"$Lt_3_21506:\n"
"	.loc	14	224	0\n"
"	ld.shared.s32 	%r95, [%rd38+0];\n"
"	set.lt.u32.s32 	%r96, %r43, %r95;\n"
"	neg.s32 	%r97, %r96;\n"
"	set.lt.u32.s32 	%r98, %r95, %r35;\n"
"	neg.s32 	%r99, %r98;\n"
"	or.b32 	%r100, %r92, %r99;\n"
"	or.b32 	%r101, %r97, %r100;\n"
"	mov.u32 	%r102, 0;\n"
"	setp.eq.s32 	%p13, %r101, %r102;\n"
"	@%p13 bra 	$Lt_3_26370;\n"
"	.loc	14	226	0\n"
"	mul.lo.u64 	%rd39, %rd37, 16;\n"
"	add.u64 	%rd40, %rd6, %rd39;\n"
"	mov.f32 	%f27, %f13;\n"
"	ld.shared.f32 	%f28, [%rd40+0];\n"
"	sub.f32 	%f29, %f27, %f28;\n"
"	.loc	14	227	0\n"
"	mov.f32 	%f30, %f14;\n"
"	ld.shared.f32 	%f31, [%rd40+4];\n"
"	sub.f32 	%f32, %f30, %f31;\n"
"	.loc	14	228	0\n"
"	mov.f32 	%f33, %f15;\n"
"	ld.shared.f32 	%f34, [%rd40+8];\n"
"	sub.f32 	%f35, %f33, %f34;\n"
"	.loc	14	226	0\n"
"	mul.f32 	%f36, %f32, %f32;\n"
"	mad.f32 	%f37, %f29, %f29, %f36;\n"
"	mad.f32 	%f38, %f35, %f35, %f37;\n"
"	ld.param.f32 	%f39, [__cudaparm_calc_neigh_list_cell_cell_size];\n"
"	mul.f32 	%f40, %f39, %f39;\n"
"	setp.lt.f32 	%p14, %f38, %f40;\n"
"	@!%p14 bra 	$Lt_3_26370;\n"
"	cvt.f64.f32 	%fd1, %f38;\n"
"	mov.f64 	%fd2, 0d3ee4f8b588e368f1;	\n"
"	setp.gt.f64 	%p15, %fd1, %fd2;\n"
"	@!%p15 bra 	$Lt_3_26370;\n"
"	ld.param.s32 	%r103, [__cudaparm_calc_neigh_list_cell_neigh_bin_size];\n"
"	setp.le.s32 	%p16, %r103, %r51;\n"
"	@%p16 bra 	$Lt_3_22274;\n"
"	.loc	14	233	0\n"
"	st.global.s32 	[%rd24+0], %r95;\n"
"	.loc	14	234	0\n"
"	mul.lo.u64 	%rd41, %rd22, 4;\n"
"	add.u64 	%rd24, %rd24, %rd41;\n"
"$Lt_3_22274:\n"
"	.loc	14	236	0\n"
"	add.s32 	%r51, %r51, 1;\n"
"$Lt_3_26370:\n"
"$L_3_14082:\n"
"$Lt_3_21762:\n"
"	add.s32 	%r93, %r93, 1;\n"
"	add.u64 	%rd37, %rd37, 1;\n"
"	add.u64 	%rd38, %rd38, 4;\n"
"	setp.ne.s32 	%p17, %r82, %r93;\n"
"	@%p17 bra 	$Lt_3_21506;\n"
"$Lt_3_20994:\n"
"$Lt_3_20482:\n"
"	.loc	14	241	0\n"
"	bar.sync 	0;\n"
"	add.s32 	%r77, %r77, 64;\n"
"	setp.ne.s32 	%p18, %r77, %r78;\n"
"	@%p18 bra 	$Lt_3_19714;\n"
"$Lt_3_19202:\n"
"	add.s32 	%r68, %r68, 1;\n"
"	add.u64 	%rd27, %rd27, 4;\n"
"	setp.ne.s32 	%p19, %r68, %r69;\n"
"	@%p19 bra 	$Lt_3_18946;\n"
"$Lt_3_18434:\n"
"	add.s32 	%r56, %r56, 1;\n"
"	setp.ne.s32 	%p20, %r59, %r56;\n"
"	@%p20 bra 	$Lt_3_18178;\n"
"$Lt_3_17666:\n"
"	add.s32 	%r50, %r50, 1;\n"
"	setp.ne.s32 	%p21, %r54, %r50;\n"
"	@%p21 bra 	$Lt_3_17410;\n"
"	bra.uni 	$Lt_3_16898;\n"
"$Lt_3_25090:\n"
"$Lt_3_16898:\n"
"	@!%p4 bra 	$Lt_3_24066;\n"
"	.loc	14	247	0\n"
"	st.global.s32 	[%rd17+0], %r51;\n"
"$Lt_3_24066:\n"
"	.loc	14	169	0\n"
"	add.s32 	%r42, %r42, 1;\n"
"	add.u32 	%r34, %r34, %r15;\n"
"	add.s32 	%r37, %r37, %r15;\n"
"	cvt.rn.f32.s32 	%f41, %r42;\n"
"	setp.lt.f32 	%p22, %f41, %f4;\n"
"	@%p22 bra 	$Lt_3_15106;\n"
"$Lt_3_14594:\n"
"	.loc	14	249	0\n"
"	exit;\n"
"$LDWend_calc_neigh_list_cell:\n"
"	}\n"
"	.entry kernel_special (\n"
"		.param .u64 __cudaparm_kernel_special_dev_nbor,\n"
"		.param .u64 __cudaparm_kernel_special_host_nbor_list,\n"
"		.param .u64 __cudaparm_kernel_special_tag,\n"
"		.param .u64 __cudaparm_kernel_special_nspecial,\n"
"		.param .u64 __cudaparm_kernel_special_special,\n"
"		.param .s32 __cudaparm_kernel_special_inum,\n"
"		.param .s32 __cudaparm_kernel_special_nt,\n"
"		.param .s32 __cudaparm_kernel_special_nall)\n"
"	{\n"
"	.reg .u32 %r<31>;\n"
"	.reg .u64 %rd<31>;\n"
"	.reg .pred %p<11>;\n"
"	.loc	14	254	0\n"
"$LBB1_kernel_special:\n"
"	cvt.s32.u16 	%r1, %ctaid.x;\n"
"	cvt.s32.u16 	%r2, %ntid.x;\n"
"	mul24.lo.s32 	%r3, %r1, %r2;\n"
"	cvt.u32.u16 	%r4, %tid.x;\n"
"	add.u32 	%r5, %r3, %r4;\n"
"	ld.param.s32 	%r6, [__cudaparm_kernel_special_nt];\n"
"	setp.le.s32 	%p1, %r6, %r5;\n"
"	@%p1 bra 	$Lt_4_6146;\n"
"	.loc	14	262	0\n"
"	ld.param.u64 	%rd1, [__cudaparm_kernel_special_nspecial];\n"
"	mul.lo.s32 	%r7, %r5, 3;\n"
"	cvt.s64.s32 	%rd2, %r7;\n"
"	mul.lo.u64 	%rd3, %rd2, 4;\n"
"	add.u64 	%rd4, %rd1, %rd3;\n"
"	ld.global.s32 	%r8, [%rd4+0];\n"
"	.loc	14	263	0\n"
"	ld.global.s32 	%r9, [%rd4+4];\n"
"	.loc	14	264	0\n"
"	ld.global.s32 	%r10, [%rd4+8];\n"
"	ld.param.s32 	%r11, [__cudaparm_kernel_special_inum];\n"
"	cvt.u64.s32 	%rd5, %r11;\n"
"	cvt.u64.s32 	%rd6, %r5;\n"
"	setp.le.s32 	%p2, %r11, %r5;\n"
"	@%p2 bra 	$Lt_4_6914;\n"
"	.loc	14	267	0\n"
"	mov.s32 	%r12, %r11;\n"
"	.loc	14	268	0\n"
"	ld.param.u64 	%rd7, [__cudaparm_kernel_special_dev_nbor];\n"
"	add.u64 	%rd8, %rd5, %rd6;\n"
"	mul.lo.u64 	%rd9, %rd8, 4;\n"
"	add.u64 	%rd10, %rd7, %rd9;\n"
"	bra.uni 	$Lt_4_6658;\n"
"$Lt_4_6914:\n"
"	.loc	14	270	0\n"
"	sub.s32 	%r12, %r6, %r11;\n"
"	.loc	14	271	0\n"
"	ld.param.u64 	%rd11, [__cudaparm_kernel_special_host_nbor_list];\n"
"	mul.lo.u64 	%rd12, %rd6, 4;\n"
"	add.u64 	%rd13, %rd11, %rd12;\n"
"	mul.lo.u64 	%rd14, %rd5, 4;\n"
"	sub.u64 	%rd10, %rd13, %rd14;\n"
"$Lt_4_6658:\n"
"	.loc	14	273	0\n"
"	ld.global.s32 	%r13, [%rd10+0];\n"
"	.loc	14	274	0\n"
"	cvt.u64.s32 	%rd15, %r12;\n"
"	mul.lo.u64 	%rd16, %rd15, 4;\n"
"	add.u64 	%rd10, %rd10, %rd16;\n"
"	.loc	14	275	0\n"
"	mul.lo.s32 	%r14, %r12, %r13;\n"
"	cvt.s64.s32 	%rd17, %r14;\n"
"	mul.lo.u64 	%rd18, %rd17, 4;\n"
"	add.u64 	%rd19, %rd10, %rd18;\n"
"	setp.le.u64 	%p3, %rd19, %rd10;\n"
"	@%p3 bra 	$Lt_4_7170;\n"
"	mov.s32 	%r15, 0;\n"
"	setp.gt.s32 	%p4, %r10, %r15;\n"
"	ld.param.u64 	%rd20, [__cudaparm_kernel_special_tag];\n"
"$Lt_4_7682:\n"
"	.loc	14	278	0\n"
"	ld.global.s32 	%r16, [%rd10+0];\n"
"	.loc	14	279	0\n"
"	cvt.u64.s32 	%rd21, %r16;\n"
"	mul.lo.u64 	%rd22, %rd21, 4;\n"
"	add.u64 	%rd23, %rd20, %rd22;\n"
"	ld.global.s32 	%r17, [%rd23+0];\n"
"	@!%p4 bra 	$Lt_4_7938;\n"
"	mov.s32 	%r18, %r10;\n"
"	mul.lo.u64 	%rd24, %rd6, 4;\n"
"	cvt.s64.s32 	%rd25, %r6;\n"
"	mul.lo.u64 	%rd26, %rd25, 4;\n"
"	ld.param.u64 	%rd27, [__cudaparm_kernel_special_special];\n"
"	add.u64 	%rd28, %rd27, %rd24;\n"
"	mov.s32 	%r19, 0;\n"
"	mov.s32 	%r20, %r18;\n"
"$Lt_4_8450:\n"
"	ld.global.s32 	%r21, [%rd28+0];\n"
"	setp.ne.s32 	%p5, %r21, %r17;\n"
"	@%p5 bra 	$Lt_4_8706;\n"
"	.loc	14	289	0\n"
"	setp.le.s32 	%p6, %r8, %r19;\n"
"	mov.s32 	%r22, 3;\n"
"	mov.s32 	%r23, 2;\n"
"	selp.s32 	%r24, %r22, %r23, %p6;\n"
"	mov.s32 	%r25, 2;\n"
"	mov.s32 	%r26, 1;\n"
"	selp.s32 	%r27, %r25, %r26, %p6;\n"
"	setp.le.s32 	%p7, %r9, %r19;\n"
"	selp.s32 	%r28, %r24, %r27, %p7;\n"
"	shl.b32 	%r29, %r28, 30;\n"
"	xor.b32 	%r16, %r16, %r29;\n"
"	.loc	14	290	0\n"
"	st.global.s32 	[%rd10+0], %r16;\n"
"$Lt_4_8706:\n"
"	add.s32 	%r19, %r19, 1;\n"
"	add.u64 	%rd28, %rd26, %rd28;\n"
"	setp.ne.s32 	%p8, %r10, %r19;\n"
"	@%p8 bra 	$Lt_4_8450;\n"
"$Lt_4_7938:\n"
"	.loc	14	277	0\n"
"	mul.lo.u64 	%rd29, %rd15, 4;\n"
"	add.u64 	%rd10, %rd10, %rd29;\n"
"	setp.gt.u64 	%p9, %rd19, %rd10;\n"
"	@%p9 bra 	$Lt_4_7682;\n"
"$Lt_4_7170:\n"
"$Lt_4_6146:\n"
"	.loc	14	296	0\n"
"	exit;\n"
"$LDWend_kernel_special:\n"
"	}\n"
;