#!/hfe/ova/rai clguba
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
        qg_fgneg = qg.qngrgvzr(2011,  2,  1)
        qg_raq   = qg.qngrgvzr(2011, 12, 31)
        fgbpxf   = ["TBBT", "NNCY", "TYQ", "KBZ"]
        nyybpf   = [0.2, 0.3, 0.4, 0.1],
    ryfr:
        qg_fgneg = qg.qngrgvzr.fgecgvzr(flf.neti[1], "%L-%z-%q")
        qg_raq   = qg.qngrgvzr.fgecgvzr(flf.neti[2], "%L-%z-%q")
        fgbpxf   = flf.neti[3].fcyvg(",")
        nyybpf   = flf.neti[4].fcyvg(",")

    iby, qnvyl_erg, funecr, phz_erg = fvzhyngr(
        qg_fgneg, qg_raq, fgbpxf, nyybpf
    )

    bcg_iby, bcg_qnvyl_erg, bcg_funecr, bcg_phz_erg, nyybpf = bcgvzny_cbegsbyvb(qg_fgneg, qg_raq, fgbpxf, nyybpf)


    cevag "=========================================================="       ### Rknzcyr ######################
    cevag "Fgneg Qngr: %f" % qg_fgneg.fgesgvzr("%O %q, %L")                  # Wnahnel 1, 2011
    cevag "Raq Qngr: %f" % qg_raq.fgesgvzr("%O %q, %L")                      # Qrprzore 31, 2011
    cevag "Flzobyf: %f" % fgbpxf                                             # ['NNCY', 'TBBT', 'KBZ', 'TYQ']
    cevag "Bcgvzny Nyybpngvbaf: %f" % nyybpf                                 # [0.4, 0.0, 0.2, 0.4]
    cevag "Funecr Engvb: %f" % bcg_funecr                                    # 1.11205126521
    cevag "Ibyngvyvgl (fgqri bs qnvyl ergheaf): %f" % bcg_iby                # 0.0101892118984
    cevag "Nirentr Qnvyl Erghea: %f" % bcg_qnvyl_erg                         # 0.000713781244655
    cevag "Phzhyngvir Erghea: %f" % bcg_phz_erg                              # 1.18144476777


qrs bcgvzny_cbegsbyvb(qg_fgneg, qg_raq, fgbpxf, nyybpf):
    bcg_iby, bcg_qnvyl_erg, bcg_funecr, bcg_phz_erg, bcg_nyybp = 0, 0, 0, 0, nyybpf

    sbe v1 va ac.nenatr(0, 1, 0.1):

        sbe v2 va ac.nenatr(0, 1, 0.1):

            sbe v3 va ac.nenatr(0, 1, 0.1):

                sbe v4 va ac.nenatr(0, 1, 0.1):
                    nyybpf = ac.nebhaq([v1, v2, v3, v4], qrpvznyf=1)
                    vs abg ac.fhz(nyybpf) == 1.0:
                        oernx

                    iby, qnvyl_erg, funecr, phz_erg = fvzhyngr(
                        qg_fgneg, qg_raq, fgbpxf, nyybpf
                    )

                    # Tbbq funecr sbhaq! Bcgvzny sbe abj
                    vs funecr > bcg_funecr:
                        bcg_iby, bcg_qnvyl_erg, bcg_funecr, bcg_phz_erg, bcg_nyybpf = iby, qnvyl_erg, funecr, phz_erg, nyybpf

                        # SVKZR: Ergheavat rirelguvat gb nibvq zhygvcyr ehaavat... ERZBIR!!
                        erghea bcg_iby, bcg_qnvyl_erg, bcg_funecr, bcg_phz_erg, bcg_nyybpf

    erghea bcg_iby, bcg_qnvyl_erg, bcg_funecr, bcg_phz_erg, bcg_nyybpf

qrs fvzhyngr(qg_fgneg, qg_raq, yf_flzobyf, nyybpngvbaf):
    # Jr arrq pybfvat cevprf fb gur gvzrfgnzc fubhyq or ubhef=16.
    qg_gvzrbsqnl = qg.gvzrqrygn(ubhef=16)

    # Trg n yvfg bs genqvat qnlf orgjrra gur fgneg naq gur raq.
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(qg_fgneg, qg_raq, qg_gvzrbsqnl)

    dfqngn = bf.cngu.wbva(bf.cngu.qveanzr(__svyr__), '..', 'svkgherf')
    bhgchg = bf.cngu.wbva(bf.cngu.qveanzr(__svyr__), '..', 'bhgchg')
    qngn_bow = qn.QngnNpprff('Lnubb', dfqngn)

    yf_xrlf = ['pybfr']

    # Ernqvat gur qngn, abj q_qngn vf n qvpgvbanel jvgu gur xrlf nobir.
    # Gvzrfgnzcf naq flzobyf ner gur barf gung jrer fcrpvsvrq orsber.
    yqs_qngn = qngn_bow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)
    q_qngn = qvpg(mvc(yf_xrlf, yqs_qngn))

    inyhrf = q_qngn["pybfr"].inyhrf
    qnvyl_ergf = inyhrf

    genqvat_qnlf = 252
    fgqqri = ac.fgq(qnvyl_ergf)
    funecr = zngu.fdeg(genqvat_qnlf) * ac.zrna(inyhrf)/fgqqri

    erghea fgqqri, ac.nirentr(inyhrf), funecr, ac.fhz(inyhrf)


vs __anzr__ == '__znva__':
    znva()
