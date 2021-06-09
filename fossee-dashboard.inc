<?php
function fossee_dashboard_form($form, &$form_state) {
	global $user;
	/************************ start approve book details ************************/
	if ($user->uid == 0)
	{
		$msg = drupal_set_message(t('It is mandatory to ' . l('login', 'user') . ' on this website to access the FOSSEE Dashboard.'), 'error');
		drupal_goto('user');
		return $msg;
	}
	$form['#attributes'] = array(
		'enctype' => "multipart/form-data"
	);
	$form['progress_tables'] = array(
		'#type' => 'item',
		'#markup' => '
		<style>
		table, td{
			border: 1px solid black;
			font-size:11pt !important;
			font-family: Arial !important;
		}
		</style>
	<div style="font-family: Arial !important;">
<h3><span style="color: #000000;"><span style="font-size: 18px;">About</span></span></h3>
<div class="container" style="line-height: 2em; font-size: 11pt;"><span style="color: #000000;">FOSSEE (Free/Libre and Open Source Software for Education) project promotes the use of FLOSS tools to improve the quality of education in our country. We aim to reduce dependency on proprietary software in educational institutions. We encourage the use of FLOSS tools through various activities to ensure commercial software is replaced by equivalent FLOSS tools. We also develop new FLOSS tools and upgrade existing tools to meet requirements in academia and research. The FOSSEE project is part of the National Mission on Education through Information and Communication Technology (ICT), Ministry of Education (MoE), Government of India.</span>
<h4><span style="color: #000000;">Active Faculty Members involved in FOSSEE</span></h4>
<table dir="ltr" style="table-layout: fixed; font-size: 10pt; width: 100%; font-family: Arial; border-collapse: collapse; border: none;" border="1" cellspacing="0" cellpadding="0">
<tbody>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 10%; text-align: right;"><span style="color: #000000;">1</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Kannan Mani Moudgalya</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Chemical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;"><span style="color: #000000;">PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">2</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. P Sunthar</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Chemical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">3</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Siddhartha Ghosh</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Civil Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">4</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Pennan Chinnasamy</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Centre for Tech. Alt. For Rural Areas</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">5</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Pramod Murali</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Electrical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">6</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Janani Srree Murallidharan</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Mechanical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">7</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Kumar Appaiah</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Electrical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">8</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Radhendushka Srivastava</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Mathematics</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">9</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Prabhu Ramachandran</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Aerospace Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">10</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Ashutosh Mahajan</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Industrial Eng. &amp; Operations Research</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">11</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Manaswita Bose</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" ><span style="color: #000000;">Dept. of Energy Sci. &amp; Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;"><span style="color: #000000;">12</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Prof. Madhu Belur<br /></span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;"><span style="color: #000000;">Dept. of Electrical Engg.<br /></span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15%;" ><span style="color: #000000;">CO-PI</span></td>
</tr>
</tbody>
</table>
<h3><span style="color: #000000;"><span style="font-size: 18px;">FOSSEE: Project Progress</span></span></h3>
<table dir="ltr" style="width: 100%; table-layout: fixed; font-size: 11pt !important; font-family: Arial !important; border-collapse: collapse;" border="1" cellspacing="0" cellpadding="0">
<tbody>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; background-color: #ffffff; border: 1px solid #000000; width: 13.8676%;">&nbsp;</td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; background-color: #ffffff; font-family: Arial; font-size: 11pt; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 17.9942%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;April 17 - Sep 17\n(No. of Institutions )&quot;}">April 17 - Sep 17<br />(No. of Institutions )</td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; background-color: #ffffff; font-size: 11pt; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Oct 17 &ndash; Mar 18\n(No. of Institutions )&quot;}">Oct 17 &ndash; Mar 18<br />(No. of Institutions )</td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; background-color: #ffffff; font-size: 11pt; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Apr 18 &ndash; Mar 19\n(No. of Institutions )&quot;}">Apr 18 &ndash; Mar 19<br />(No. of Institutions )</td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; background-color: #ffffff; font-size: 11pt; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Apr 19 &ndash; Mar 20\n(No. of Institutions )&quot;}">Apr 19 &ndash; Mar 20<br />(No. of Institutions )</td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; background-color: #ffffff; font-size: 11pt; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Apr 20 &ndash; Mar 21\r\n(No. of Institutions )&quot;}">Apr 20 &ndash; Mar 21 <br />(No. of Institutions )</td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 13.8676%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Target&quot;}">Target</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 17.9942%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:175}">175</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:500}">500</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1000}">1000</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1000}">1000</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1100}">1100</td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 13.8676%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Outcome&quot;}">Outcome</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 17.9942%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:189}">189</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:872}">872</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1080}">1080</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1062}">1062</td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 15.9309%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1195}">1195</td>
</tr>
</tbody>
</table>
<p>For the definition of institutions, please refer <a href="https://static.fossee.in/fossee/MoE-reports/FOSSEEdeliverables-InstituteDefinition.pdf" target="_blank">here</a>.</p>
<h3><span style="color: #000000;"><span style="font-size: 18px;">FOSSEE: Financial Progress</span></span></h3>
<table dir="ltr" style="table-layout: fixed; font-size: 10pt; font-family: Arial; width: 100%; border-collapse: collapse; border: none;" border="1" cellspacing="0" cellpadding="0">
<tbody>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; border: 1px solid #000000; width: 12%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Period&quot;}"><span style="color: #000000;">Period</span></td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; width: 43.2145%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Funds received (release date)&quot;}"><span style="color: #000000;">Funds received (release date)</span></td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: top; width: 40.7855%;"><span style="color: #000000;">&nbsp;</span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; width: 12%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;2017-18&quot;}"><span style="color: #000000;">2017-18</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 43.2145%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;3,27,14,076 (Cash in hand as on 1 April 2017)\n3 Cr. (15.01.2018)&quot;}"><span style="color: #000000;">3,27,14,076 (Cash in hand as on 1 April 2017)</span><br /><span style="color: #000000;">3 Cr. (15.01.2018)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; text-decoration: underline; white-space: normal; overflow-wrap: break-word; color: #000000; width: 40.7855%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;UC as on 31 March 2017&quot;}" data-sheets-formula="=HYPERLINK(&quot;https://fossee.in/data/UC/UC-2016-2017.pdf&quot;,&quot;UC as on 31 March 2017&quot;)" data-sheets-hyperlink="https://fossee.in/data/UC/UC-2016-2017.pdf"><span style="text-decoration: underline;"><a class="in-cell-link" style="text-decoration: underline;" href="https://fossee.in/data/UC/UC-2016-2017.pdf" target="_blank">UC as on 31 March 2017</a></span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; width: 12%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;2018-19&quot;}"><span style="color: #000000;">2018-19</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 43.2145%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;3 Cr. (23.10.2018)&quot;}"><span style="color: #000000;">3 Cr. (23.10.2018)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; text-decoration: underline; white-space: normal; overflow-wrap: break-word; color: #000000; width: 40.7855%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;UC as on 31 March 2018&quot;}" data-sheets-formula="=HYPERLINK(&quot;https://fossee.in/data/UC/UC-2017-2018.pdf&quot;,&quot;UC as on 31 March 2018&quot;)" data-sheets-hyperlink="https://fossee.in/data/UC/UC-2017-2018.pdf"><span style="text-decoration: underline;"><a class="in-cell-link" style="text-decoration: underline;" href="https://fossee.in/data/UC/UC-2017-2018.pdf" target="_blank">UC as on 31 March 2018</a></span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; width: 12%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;2019-20&quot;}"><span style="color: #000000;">2019-20</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 43.2145%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;1.52 Cr (17.06.2019)\n2.38 Cr (17.09.2019)\n3.09 Cr (5.11.2019)&quot;}"><span style="color: #000000;">1.52 Cr (17.06.2019)</span><br /><span style="color: #000000;">2.38 Cr (17.09.2019)</span><br /><span style="color: #000000;">3.09 Cr (5.11.2019)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; text-decoration: underline; white-space: normal; overflow-wrap: break-word; color: #000000; width: 40.7855%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;UC as on 31 March 2019&quot;}" data-sheets-formula="=HYPERLINK(&quot;https://fossee.in/data/UC/UC-2018-2019.pdf&quot;,&quot;UC as on 31 March 2019&quot;)" data-sheets-hyperlink="https://fossee.in/data/UC/UC-2018-2019.pdf"><span style="text-decoration: underline;"><a class="in-cell-link" style="text-decoration: underline;" href="https://fossee.in/data/UC/UC-2018-2019.pdf" target="_blank">UC as on 31 March 2019</a></span></td>
</tr>
</tbody>
</table>
</div>
'
	);
	return $form;
}