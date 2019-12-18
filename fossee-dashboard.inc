<?php
function fossee_dashboard_form($form, &$form_state) {
	global $user;
	/************************ start approve book details ************************/
	if ($user->uid == 0)
	{
		$msg = drupal_set_message(t('It is mandatory to ' . l('login', 'user') . ' on this website to access the case study proposal form. If you are new user please create a new account first.'), 'error');
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
<div class="container" style="line-height: 2em; font-size: 11pt;"><span style="color: #000000;">FOSSEE (Free/Libre and Open Source Software for Education) project promotes the use of FLOSS tools to improve the quality of education in our country. We aim to reduce dependency on proprietary software in educational institutions. We encourage the use of FLOSS tools through various activities to ensure commercial software is replaced by equivalent FLOSS tools. We also develop new FLOSS tools and upgrade existing tools to meet requirements in academia and research. The FOSSEE project is part of the National Mission on Education through Information and Communication Technology (ICT), Ministry of Human Resource Development (MHRD), Government of India.</span>
<h4><span style="color: #000000;">Active Faculty Members involved in FOSSEE</span></h4>
<table dir="ltr" style="table-layout: fixed; font-size: 10pt; width: 100%; font-family: Arial; border-collapse: collapse; border: none;" border="1" cellspacing="0" cellpadding="0">
<tbody>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1}"><span style="color: #000000;">1</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Kannan Mani Moudgalya&quot;}"><span style="color: #000000;">Kannan Mani Moudgalya</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Chemical Engg.&quot;}"><span style="color: #000000;">Dept. of Chemical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;PI&quot;}"><span style="color: #000000;">PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:2}"><span style="color: #000000;">2</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;P Sunthar&quot;}"><span style="color: #000000;">P Sunthar</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Chemical Engg.&quot;}"><span style="color: #000000;">Dept. of Chemical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:3}"><span style="color: #000000;">3</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Siddhartha Ghosh&quot;}"><span style="color: #000000;">Siddhartha Ghosh</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Civil Engg.&quot;}"><span style="color: #000000;">Dept. of Civil Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:4}"><span style="color: #000000;">4</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Pennan Chinnasamy&quot;}"><span style="color: #000000;">Pennan Chinnasamy</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Centre for Tech. Alt. For Rural Areas&quot;}"><span style="color: #000000;">Centre for Tech. Alt. For Rural Areas</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:5}"><span style="color: #000000;">5</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Pramod Murali&quot;}"><span style="color: #000000;">Pramod Murali</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Electrical Engg.&quot;}"><span style="color: #000000;">Dept. of Electrical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:6}"><span style="color: #000000;">6</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Janani Srree Murallidharan&quot;}"><span style="color: #000000;">Janani Srree Murallidharan</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Mechanical Engg.&quot;}"><span style="color: #000000;">Dept. of Mechanical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:7}"><span style="color: #000000;">7</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Kumar Appaiah&quot;}"><span style="color: #000000;">Kumar Appaiah</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Electrical Engg.&quot;}"><span style="color: #000000;">Dept. of Electrical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:8}"><span style="color: #000000;">8</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Radhendushka Srivastava&quot;}"><span style="color: #000000;">Radhendushka Srivastava</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Mathematics&quot;}"><span style="color: #000000;">Dept. of Mathematics</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:9}"><span style="color: #000000;">9</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Prabhu Ramachandran&quot;}"><span style="color: #000000;">Prabhu Ramachandran</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Aerospace Engg.&quot;}"><span style="color: #000000;">Dept. of Aerospace Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:10}"><span style="color: #000000;">10</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Ashutosh Mahajan&quot;}"><span style="color: #000000;">Ashutosh Mahajan</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Industrial Eng. &amp; Operations Research&quot;}"><span style="color: #000000;">Industrial Eng. &amp; Operations Research</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:11}"><span style="color: #000000;">11</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Manaswita Bose&quot;}"><span style="color: #000000;">Manaswita Bose</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Energy Sci. &amp; Engg.&quot;}"><span style="color: #000000;">Dept. of Energy Sci. &amp; Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; text-align: right; width: 10%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:12}"><span style="color: #000000;">12</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Shivasubramanian Gopalakrishnan&quot;}"><span style="color: #000000;">Shivasubramanian Gopalakrishnan</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 34.5853%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Dept. of Mechanical Engg.&quot;}"><span style="color: #000000;">Dept. of Mechanical Engg.</span></td>
<td style="overflow: hidden; padding: 2px 3px; vertical-align: bottom; width: 15.4147%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;CO-PI&quot;}"><span style="color: #000000;">CO-PI</span></td>
</tr>
</tbody>
</table>
</div>
<h3><span style="color: #000000;"><span style="font-size: 18px;">FOSSEE: Project Progress</span></span></h3>
<table dir="ltr" style="width: 100%; table-layout: fixed; font-size: 11pt !important; font-family: Arial !important; border-collapse: collapse;" border="1" cellspacing="0" cellpadding="0">
<tbody>
<tr style="height: 21px;">
<td style="overflow: hidden; padding: 2px 3px; vertical-align: top; background-color: #ffffff; border: 1px solid #000000; width: 10%;"><br /><span style="color: #000000;">&nbsp;</span></td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-size: 11pt; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 28%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Attribute / Outcome&quot;}"><span style="color: #000000;">Attribute / Outcome</span></td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-size: 11pt; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 19%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;April 17 - Sep 17\n(Target: 175 Institutions )&quot;}"><span style="color: #000000;">April 17 - Sep 17</span><br /><span style="color: #000000;">(Target: 175 Institutions )</span></td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-size: 11pt; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 16.5895%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Oct 17 &ndash; Sep 18 (Target: 1000 Institutions)&quot;}"><span style="color: #000000;">Oct 17 &ndash; Sep 18 </span><br /><span style="color: #000000;">(Target: 1000 Institutions)</span></td>
<td style="border-top: 1px solid #000000; border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-size: 11pt; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 19.4105%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Oct 18 &ndash; Sep 19\n(Target: 1000 Institutions)&quot;}"><span style="color: #000000;">Oct 18 &ndash; Sep 19</span><br /><span style="color: #000000;">(Target: 1000 Institutions)</span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-size: 11pt; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 10%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;(i)&quot;}"><span style="color: #000000;">(i)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 28%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;FOSSEE Activities: TBC, LM DWSIM Flowsheets, OpenFOAM Case studies, eSim simulations, etc.&quot;}"><span style="color: #000000;">FOSSEE Activities: TBC, LM DWSIM Flowsheets, OpenFOAM Case studies, eSim simulations, etc.</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:189}"><span style="color: #000000;">189</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 16.5895%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:44}"><span style="color: #000000;">44</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19.4105%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:106}"><span style="color: #000000;">106</span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-size: 11pt; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 10%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;(ii)&quot;}"><span style="color: #000000;">(ii)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 28%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Workshops and conferences&quot;}"><span style="color: #000000;">Workshops and conferences</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;--&quot;}"><span style="color: #000000;">--</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 16.5895%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:877}"><span style="color: #000000;">877</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19.4105%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:898}"><span style="color: #000000;">898</span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-size: 11pt; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 10%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;iii)&quot;}"><span style="color: #000000;">iii)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 28%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Fellowship&quot;}"><span style="color: #000000;">Fellowship</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;--&quot;}"><span style="color: #000000;">--</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 16.5895%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:200}"><span style="color: #000000;">200</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19.4105%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:250}"><span style="color: #000000;">250</span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 10%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;(iv)&quot;}"><span style="color: #000000;">(iv)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 28%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Online evaluator&quot;}"><span style="color: #000000;">Online evaluator</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;--&quot;}"><span style="color: #000000;">--</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 16.5895%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:89}"><span style="color: #000000;">89</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19.4105%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:48}"><span style="color: #000000;">48</span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: top; background-color: #ffffff; width: 10%;"><span style="color: #000000;">&nbsp;</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 28%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Total&quot;}"><span style="color: #000000;">Total</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:189}"><span style="color: #000000;">189</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 16.5895%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1363}"><span style="color: #000000;">1363</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-family: Arial; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 19.4105%;" data-sheets-value="{&quot;1&quot;:3,&quot;3&quot;:1302}"><span style="color: #000000;">1302</span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: top; background-color: #ffffff; width: 10%;"><span style="color: #000000;">&nbsp;</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; background-color: #ffff00; font-family: Arial; font-size: 11pt; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; text-align: center; width: 83%;" colspan="4" rowspan="1" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;Oct 19 &ndash; Mar 20: target 500 Institutions&quot;}"><span style="color: #000000;">Oct 19 &ndash; Mar 20: target 500 Institutions</span></td>
</tr>
</tbody>
</table>
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
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; text-decoration: underline; white-space: normal; overflow-wrap: break-word; color: #000000; width: 40.7855%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;UC as on 31 March 2017&quot;}" data-sheets-formula="=HYPERLINK(&quot;https://fossee.in/data/UC/UC-2016-2017.pdf&quot;,&quot;UC as on 31 March 2017&quot;)" data-sheets-hyperlink="https://fossee.in/data/UC/UC-2016-2017.pdf"><span style="color: #000000; text-decoration: underline;"><a class="in-cell-link" style="color: #000000; text-decoration: underline;" href="https://fossee.in/data/UC/UC-2016-2017.pdf" target="_blank">UC as on 31 March 2017</a></span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; width: 12%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;2018-19&quot;}"><span style="color: #000000;">2018-19</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 43.2145%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;3 Cr. (23.10.2018)&quot;}"><span style="color: #000000;">3 Cr. (23.10.2018)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; text-decoration: underline; white-space: normal; overflow-wrap: break-word; color: #000000; width: 40.7855%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;UC as on 31 March 2018&quot;}" data-sheets-formula="=HYPERLINK(&quot;https://fossee.in/data/UC/UC-2017-2018.pdf&quot;,&quot;UC as on 31 March 2018&quot;)" data-sheets-hyperlink="https://fossee.in/data/UC/UC-2017-2018.pdf"><span style="color: #000000; text-decoration: underline;"><a class="in-cell-link" style="color: #000000; text-decoration: underline;" href="https://fossee.in/data/UC/UC-2017-2018.pdf" target="_blank">UC as on 31 March 2018</a></span></td>
</tr>
<tr style="height: 21px;">
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; border-left: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: bold; white-space: normal; overflow-wrap: break-word; color: #000000; width: 12%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;2019-20&quot;}"><span style="color: #000000;">2019-20</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; white-space: normal; overflow-wrap: break-word; color: #000000; width: 43.2145%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;1.52 Cr (17.06.2019)\n2.38 Cr (17.09.2019)\n3.09 Cr (5.11.2019)&quot;}"><span style="color: #000000;">1.52 Cr (17.06.2019)</span><br /><span style="color: #000000;">2.38 Cr (17.09.2019)</span><br /><span style="color: #000000;">3.09 Cr (5.11.2019)</span></td>
<td style="border-right: 1px solid #000000; border-bottom: 1px solid #000000; overflow: hidden; padding: 2px 3px; vertical-align: bottom; font-weight: normal; text-decoration: underline; white-space: normal; overflow-wrap: break-word; color: #000000; width: 40.7855%;" data-sheets-value="{&quot;1&quot;:2,&quot;2&quot;:&quot;UC as on 31 March 2019&quot;}" data-sheets-formula="=HYPERLINK(&quot;https://fossee.in/data/UC/UC-2018-2019.pdf&quot;,&quot;UC as on 31 March 2019&quot;)" data-sheets-hyperlink="https://fossee.in/data/UC/UC-2018-2019.pdf"><span style="color: #000000; text-decoration: underline;"><a class="in-cell-link" style="color: #000000; text-decoration: underline;" href="https://fossee.in/data/UC/UC-2018-2019.pdf" target="_blank">UC as on 31 March 2019</a></span></td>
</tr>
</tbody>
</table>
</div>
'
	);
	return $form;
}