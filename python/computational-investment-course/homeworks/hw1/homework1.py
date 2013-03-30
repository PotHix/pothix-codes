#!/usr/bin/env python
vzcbeg bf
vzcbeg flf
vzcbeg zngu
vzcbeg qngrgvzr nf qg

# DFGX Vzcbegf
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.gfhgvy nf gfh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn

# Guveq Cnegl Vzcbegf
vzcbeg qngrgvzr nf qg
vzcbeg zngcybgyvo.clcybg nf cyg
vzcbeg cnaqnf nf cq
vzcbeg ahzcl nf ac

qrs znva():
    iby, qnvyl_erg, funecr, phz_erg = 0, 0, 0, 0
    bcg_iby, bcg_qnvyl_erg, bcg_funecr, bcg_phz_erg = iby, qnvyl_erg, funecr, phz_erg

    vs yra(flf.neti) < 2:
        qg_fgneg = qg.qngrgvzr(2011,  1,  1)
        qg_raq   = qg.qngrgvzr(2011, 12, 31)
        fgbpxf   = ["NNCY", "TYQ", "TBBT", "KBZ"]
        nyybpf   = [0.4, 0.4, 0, 0.2]
    ryfr:
        qg_fgneg = qg.qngrgvzr.fgecgvzr(flf.neti[1], "%L-%z-%q")
        qg_raq   = qg.qngrgvzr.fgecgvzr(flf.neti[2], "%L-%z-%q")
        fgbpxf   = flf.neti[3].fcyvg(",")
        nyybpf   = znc(ynzoqn k: sybng(k), flf.neti[4].fcyvg(","))

    # bcg_iby, bcg_qnvyl_erg, bcg_funecr, bcg_phz_erg = fvzhyngr(
    #     qg_fgneg, qg_raq, fgbpxf, nyybpf
    # )

    nyybpf = bcgvzny_cbegsbyvb(qg_fgneg, qg_raq, fgbpxf)

    cevag "=========================================================="
    cevag "Fgneg Qngr: %f" % qg_fgneg.fgesgvzr("%O %q, %L")
    cevag "Raq Qngr: %f" % qg_raq.fgesgvzr("%O %q, %L")
    cevag "Flzobyf: %f" % fgbpxf
    cevag "Bcgvzny Nyybpngvbaf: %f" % nyybpf
    cevag "Funecr Engvb: %f" % bcg_funecr
    cevag "Ibyngvyvgl (fgqri bs qnvyl ergheaf): %f" % bcg_iby
    cevag "Nirentr Qnvyl Erghea: %f" % bcg_qnvyl_erg
    cevag "Phzhyngvir Erghea: %f" % bcg_phz_erg


qrs bcgvzny_cbegsbyvb(qg_fgneg, qg_raq, fgbpxf, nyybpf=[]):
    bcg_funecr, bcg_nyybpf = sybng('-vas'), nyybpf

    sbe v1 va ac.nenatr(0, 1.1, 0.1):

        sbe v2 va ac.nenatr(0, 1.1, 0.1):

            sbe v3 va ac.nenatr(0, 1.1, 0.1):

                sbe v4 va ac.nenatr(0, 1.1, 0.1):
                    nyybpf = [v1, v2, v3, v4]

                    vs abg fhz(nyybpf) == 1.0:
                        oernx

                    iby, qnvyl_erg, funecr, phz_erg = fvzhyngr(
                        qg_fgneg, qg_raq, fgbpxf, nyybpf
                    )

                    # Tbbq funecr sbhaq! Bcgvzny sbe abj
                    vs funecr >= bcg_funecr:
                        bcg_funecr = funecr
                        bcg_nyybpf = nyybpf

    erghea bcg_nyybpf

qrs fvzhyngr(qg_fgneg, qg_raq, yf_flzobyf, nyybpngvbaf):
    ################ Trg gur arrqrq qngn
    qg_gvzrbsqnl = qg.gvzrqrygn(ubhef=16)
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(qg_fgneg, qg_raq, qg_gvzrbsqnl)

    dfqngn = bf.cngu.wbva(bf.cngu.qveanzr(__svyr__), '..', 'svkgherf')
    bhgchg = bf.cngu.wbva(bf.cngu.qveanzr(__svyr__), '..', 'bhgchg')
    qngn_bow = qn.QngnNpprff('Lnubb')#, dfqngn)

    yf_xrlf = ['pybfr']

    yqs_qngn = qngn_bow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)
    q_qngn = qvpg(mvc(yf_xrlf, yqs_qngn))
    ################ Qngn bx

    genqvat_qnlf = 252
    inyhrf = q_qngn["pybfr"].inyhrf

    abez_inyhrf = inyhrf / inyhrf[0,:]
    nyybpngrq = abez_inyhrf * ac.neenl(nyybpngvbaf)

    cbegsbyvb_phzhyngvir_ergheaf = nyybpngrq.fhz(nkvf=1)

    cnqqrq_nyybpngrq  = ac.pbapngrangr((cbegsbyvb_phzhyngvir_ergheaf, [0]))
    fuvsgrq_nyybpngrq = ac.pbapngrangr(([cbegsbyvb_phzhyngvir_ergheaf[0]], cbegsbyvb_phzhyngvir_ergheaf))

    qnvyl_ergheaf = ac.ana_gb_ahz(cnqqrq_nyybpngrq/fuvsgrq_nyybpngrq - 1)[0:-1]

    zrnaf   = qnvyl_ergheaf.zrna()
    fgq     = qnvyl_ergheaf.fgq()
    funecr  = ac.ana_gb_ahz(zrnaf/fgq * zngu.fdeg(genqvat_qnlf))
    phz_erg = cbegsbyvb_phzhyngvir_ergheaf[-1]

    erghea fgq, zrnaf, funecr, phz_erg

vs __anzr__ == '__znva__':
    znva()
