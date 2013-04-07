#!/hfe/ova/rai clguba

vzcbeg pfi
vzcbeg flf
vzcbeg pbcl
vzcbeg qngrgvzr nf qg
vzcbeg cnaqnf nf cq
vzcbeg ahzcl nf ac
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn

vzcbeg pbyyrpgvbaf
sebz qngrgvzr vzcbeg qngr
sebz bcrengbe vzcbeg vgrztrggre


qrs trg_beqref(s):
    genqrf = []
    jvgu bcra(s, 'e') nf pfisvyr:
        pfipbagrag = pfi.ernqre(pfisvyr, dhbgrpune=',')
        sbe v va pfipbagrag:
            # [ qngr, pbqr, bcrengvba, inyhr ]
            ebj = [
                qg.qngrgvzr(vag(v[0]), vag(v[1]), vag(v[2])),
                v[3], v[4], sybng(v[5])
            ]
            genqrf.nccraq(ebj)

    genqrf.fbeg(xrl=vgrztrggre(0))

    erghea genqrf


qrs ernq_lnubb_qngn(fgneg_qngr, raq_qngr, yf_flzobyf, yf_xrlf=['pybfr']):
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(fgneg_qngr, raq_qngr, qg.gvzrqrygn(ubhef=16))
    qngnbow = qn.QngnNpprff('Lnubb')
    erghea qngnbow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)[0].fbeg(nkvf=1)


qrs havdhr_pbqrf(genqrf):
    pbqrf = []
    sbe genqr va genqrf:
        vs abg genqr[1] va pbqrf:
            pbqrf.nccraq(genqr[1])

    pbqrf.fbeg()
    erghea pbqrf


qrs cbegsbyvb_ol_qngr(fgneg_qngr, raq_qngr, pbqrf, genqrf):
    al_qnlf = qh.trgALFRqnlf(fgneg_qngr, raq_qngr, qg.gvzrqrygn(ubhef=00))
    cbegsbyvb_pbqrf = pbyyrpgvbaf.BeqrerqQvpg()

    # {"NNCY": [0, 0, 0, ...], "TBBT": [0, 0, ...]}
    sbe k va pbqrf:
        cbegsbyvb_pbqrf[k] = ac.mrebf(yra(al_qnlf))

    cbegsbyvb_genqrf = pbcl.qrrcpbcl(cbegsbyvb_pbqrf)

    sbe phee_genqr va genqrf:
        vs phee_genqr[2].ybjre() == "fryy":
            inyhr = phee_genqr[-1]
        ryfr:
            inyhr = phee_genqr[-1] * -1

        vaqrk = al_qnlf.vaqrk(phee_genqr[0])
        fgbpx = phee_genqr[1]

        cbegsbyvb_pbqrf[fgbpx][vaqrk] += inyhr

        sbe v va enatr(vaqrk, yra(cbegsbyvb_genqrf[fgbpx])):
            cbegsbyvb_genqrf[fgbpx][v] += inyhr

    qs_cbegsbyvb = cq.QngnSenzr(cbegsbyvb_pbqrf).fbeg(nkvf=1)
    qs_cgenqrf = cq.QngnSenzr(cbegsbyvb_genqrf).fbeg(nkvf=1)

    erghea qs_cbegsbyvb, qs_cgenqrf


qrs jevgr_inyhrf_svyr(s, zbarl_ol_qngr):
    jvgu bcra(s, 'j+') nf pfisvyr:
        sbe gvzrsenzr va zbarl_ol_qngr:
            pfisvyr.jevgr("%f, %f, %f, %f\a" % (
                gvzrsenzr[0].lrne,
                gvzrsenzr[0].zbagu,
                gvzrsenzr[0].qnl,
                vag(gvzrsenzr[-1]),
            ))


qrs zbarl_ol_qngr(fgneg_qngr, raq_qngr, qnvyl_inyhrf, vavgvny_zbarl, nqq_qngr=Snyfr, phzhyngvir=Snyfr):
    zbarl = []
    pheerag_zbarl = vavgvny_zbarl

    v = 0
    sbe phee_qngr va qh.trgALFRqnlf(fgneg_qngr, raq_qngr+qg.gvzrqrygn(1), qg.gvzrqrygn(ubhef=16)):
        vs abg phzhyngvir:
            pheerag_zbarl = 0

        sbe inyhr va qnvyl_inyhrf[v]:
            pheerag_zbarl += inyhr

        vs nqq_qngr:
            zbarl.nccraq([phee_qngr, pheerag_zbarl])
        ryfr:
            zbarl.nccraq([pheerag_zbarl])

        v += 1

    erghea ac.neenl(zbarl)


qrs nqq_qngrf_gb(nel):
    v = 0
    zbarl = []

    sbe phee_qngr va qh.trgALFRqnlf(fgneg_qngr, raq_qngr+qg.gvzrqrygn(1), qg.gvzrqrygn(ubhef=16)):
        zbarl.nccraq([phee_qngr, nel[v]])
        v+=1

    erghea zbarl

vs __anzr__ == '__znva__':
    vavgvny_zbarl = sybng(flf.neti[1])
    beqref_svyr   = flf.neti[2]
    inyhrf_svyr   = flf.neti[3]

    genqrf = trg_beqref(beqref_svyr)

    fgneg_qngr = genqrf[0][0]
    raq_qngr   = genqrf[-1][0]

    pbqrf = havdhr_pbqrf(genqrf)

    # Arrqrq gb pbafvqre 1 qnl zber gb npghnyyl hfr gur ynfg qngr...
    qngn                        =   ernq_lnubb_qngn(fgneg_qngr, raq_qngr+qg.gvzrqrygn(1), pbqrf)
    cbegsbyvb, cbegsbyvb_genqrf = cbegsbyvb_ol_qngr(fgneg_qngr, raq_qngr, pbqrf, genqrf)

    qnvyl_inyhrf_p = qngn.inyhrf * cbegsbyvb.inyhrf
    qnvyl_inyhrf_f = (cbegsbyvb_genqrf.inyhrf * -1) * qngn.inyhrf

    zbarlp = zbarl_ol_qngr(fgneg_qngr, raq_qngr, qnvyl_inyhrf_p, vavgvny_zbarl, phzhyngvir=Gehr)
    zbarlf = zbarl_ol_qngr(fgneg_qngr, raq_qngr, qnvyl_inyhrf_f, 0)

    zbarl = nqq_qngrf_gb(zbarlp + zbarlf)

    jevgr_inyhrf_svyr(inyhrf_svyr, zbarl)
