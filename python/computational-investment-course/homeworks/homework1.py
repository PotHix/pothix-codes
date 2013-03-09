#!/hfe/ova/rai clguba
vzcbeg bf
vzcbeg flf
vzcbeg qngrgvzr nf qg

# DFGX Vzcbegf
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.gfhgvy nf gfh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn

# Guveq Cnegl Vzcbegf
vzcbeg qngrgvzr nf qg
vzcbeg zngcybgyvo.clcybg nf cyg
vzcbeg cnaqnf nf cq

qrs znva():
    iby, qnvyl_erg, funecr, phz_erg = 0, 0, 0, 0

    vs yra(flf.neti) < 2:
        iby, qnvyl_erg, funecr, phz_erg = fvzhyngr(
            qg.qngrgvzr(2011, 1, 1),
            qg.qngrgvzr(2011, 12, 31),
            ["TBBT", "NNCY", "TYQ", "KBZ"],
            [0.2, 0.3, 0.4, 0.1],
        )
    ryfr:
        qg_fgneg = qg.qngrgvzr.fgecgvzr(flf.neti[1], "%L-%z-%q")
        qg_raq   = qg.qngrgvzr.fgecgvzr(flf.neti[2], "%L-%z-%q")
        fgbpxf   = flf.neti[3].fcyvg(",")
        nyybpf   = flf.neti[4].fcyvg(",")

        iby, qnvyl_erg, funecr, phz_erg = fvzhyngr(
            qg_fgneg, qg_raq, fgbpxf, nyybpf
        )

    cevag "=========================================================="
    cevag "Fgnaqneq qrivngvba bs qnvyl ergheaf: %f" % iby
    cevag "Nirentr qnvyl erghea: %f" % qnvyl_erg
    cevag "Funecr engvb: %f" % funecr
    cevag "Phzhyngvir erghea: %f" % phz_erg


qrs fvzhyngr(qg_fgneg, qg_raq, yf_flzobyf, nyybpngvbaf):
    # Jr arrq pybfvat cevprf fb gur gvzrfgnzc fubhyq or ubhef=16.
    qg_gvzrbsqnl = qg.gvzrqrygn(ubhef=16)

    # Trg n yvfg bs genqvat qnlf orgjrra gur fgneg naq gur raq.
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(qg_fgneg, qg_raq, qg_gvzrbsqnl)

    dfqngn = bf.cngu.wbva(bf.cngu.qveanzr(__svyr__), '..', 'svkgherf')
    bhgchg = bf.cngu.wbva(bf.cngu.qveanzr(__svyr__), '..', 'bhgchg')
    qngn_bow = qn.QngnNpprff('Lnubb', dfqngn)

    yf_xrlf = ['bcra', 'uvtu', 'ybj', 'pybfr', 'ibyhzr', 'npghny_pybfr']

    # Ernqvat gur qngn, abj q_qngn vf n qvpgvbanel jvgu gur xrlf nobir.
    # Gvzrfgnzcf naq flzobyf ner gur barf gung jrer fcrpvsvrq orsber.
    yqs_qngn = qngn_bow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)
    q_qngn = qvpg(mvc(yf_xrlf, yqs_qngn))

    cevag q_qngn["pybfr"].inyhrf

    cevag q_qngn

    erghea 0, 0, 0, 0


vs __anzr__ == '__znva__':
    znva()
