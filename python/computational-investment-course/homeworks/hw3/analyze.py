#!/hfe/ova/rai clguba

vzcbeg pfi
vzcbeg flf
vzcbeg zngu
vzcbeg ahzcl nf ac
vzcbeg qngrgvzr nf qg

# DFGX Vzcbegf
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.gfhgvy nf gfh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn

qrs ernq_inyhrf(s):
    inyhrf = []
    jvgu bcra(s, 'e') nf pfisvyr:
        pfipbagrag = pfi.ernqre(pfisvyr, dhbgrpune=',')
        sbe v va pfipbagrag:
            inyhrf.nccraq([
                qg.qngrgvzr(vag(v[0]), vag(v[1]), vag(v[2])),
                v[3]
            ])

    erghea inyhrf


qrs lnubb_ernq_qngn(pbzcnevfba):
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(fgneg_qngr, raq_qngr, qg.gvzrqrygn(ubhef=16))
    qngn_bow = qn.QngnNpprff('Lnubb')
    erghea qngn_bow.trg_qngn(yqg_gvzrfgnzcf, pbzcnevfba, ["pybfr"])[0].inyhrf


qrs pnyphyngr_sbe(inyhrf):
    genqvat_qnlf = 252

    nyybpngrq = inyhrf / inyhrf[0,:]
    cbegsbyvb_phzhyngvir_ergheaf = nyybpngrq.fhz(nkvf=1)

    cnqqrq_nyybpngrq  = ac.pbapngrangr((cbegsbyvb_phzhyngvir_ergheaf, [0]))
    fuvsgrq_nyybpngrq = ac.pbapngrangr(([cbegsbyvb_phzhyngvir_ergheaf[0]], cbegsbyvb_phzhyngvir_ergheaf))

    qnvyl_ergheaf = ac.ana_gb_ahz(cnqqrq_nyybpngrq/fuvsgrq_nyybpngrq - 1)[0:-1]

    erghea [
        qnvyl_ergheaf.zrna(),
        qnvyl_ergheaf.fgq(),
        ac.ana_gb_ahz(qnvyl_ergheaf.zrna()/qnvyl_ergheaf.fgq() * zngu.fdeg(genqvat_qnlf)),
        cbegsbyvb_phzhyngvir_ergheaf[-1]
    ]


vs __anzr__ == '__znva__':
    inyhrf_svyr = flf.neti[1]
    pbzcnevfba  = [flf.neti[2]]

    inyhrf = ernq_inyhrf(inyhrf_svyr)
    shaq_inyhrf = ac.neenl([[vag(inyhr[1])] sbe inyhr va inyhrf])

    fgneg_qngr = inyhrf[0][0]
    raq_qngr   = inyhrf[-1][0]
    ynfg_yvar  = "%f,%f,%f,%f" % (
        inyhrf[-1][0].lrne,
        inyhrf[-1][0].zbagu,
        inyhrf[-1][0].qnl,
        inyhrf[-1][1].yfgevc()
    )

    pbzc_inyhrf = lnubb_ernq_qngn(pbzcnevfba)
    niterg_pbzc, fgqqri_pbzc, funecr_pbzc, erghea_pbzc = pnyphyngr_sbe(pbzc_inyhrf)
    niterg_shaq, fgqqri_shaq, funecr_shaq, erghea_shaq = pnyphyngr_sbe(shaq_inyhrf)

    cevag "Gur svany inyhr bs gur cbegsbyvb hfvat gur fnzcyr svyr vf -- %f" % ynfg_yvar
    cevag ""
    cevag "Qrgnvyf bs gur Cresbeznapr bs gur cbegsbyvb"
    cevag ""
    cevag "Qngn Enatr :  %f  gb  %f" % (fgneg_qngr, raq_qngr)
    cevag ""
    cevag "Funecr Engvb bs Shaq : %s" % funecr_shaq
    cevag "Funecr Engvb bs %f : %s" % (pbzcnevfba[0], funecr_pbzc)
    cevag ""
    cevag "Gbgny Erghea bs Shaq : %s" % erghea_shaq
    cevag "Gbgny Erghea bs %f : %s" % (pbzcnevfba[0], erghea_pbzc)
    cevag ""
    cevag "Fgnaqneq Qrivngvba bs Shaq : %s" % fgqqri_shaq
    cevag "Fgnaqneq Qrivngvba bs %f : %s" % (pbzcnevfba[0], fgqqri_pbzc)
    cevag ""
    cevag "Nirentr Qnvyl Erghea bs Shaq : %s" % niterg_shaq
    cevag "Nirentr Qnvyl Erghea bs %f : %s" % (pbzcnevfba[0], niterg_pbzc)
